#include<string>
#include<iostream>
#include<map>
#include<time.h>
#include<WinBase.h>
#include<windows.h>
#include<mutex>
#include<shared_mutex>

using namespace std;

#define N 100
#define T 6000
typedef string K;
typedef string V;


class KV {
private:
	V v;
	K k;
	int count;
	map<K,V> m_mapKV;//�洢K��V
	map<K,unsigned int> m_mapKTime;//�洢K-Time	
	typedef unique_lock<std::mutex> guarded_mutex;
	std::mutex mtx_;//������

public:
	V Get(K);
	void Set(K, V);
	void autoremove();//����ʱ��Tɾ��

};

V KV::Get(K k){
	map<K, V>::iterator find_kv;
	
	guarded_mutex guard{ mtx_ };//�Դ����mtx_ ����

	autoremove();//��������map

	find_kv = m_mapKV.find(k);
	if (find_kv != m_mapKV.end())
		return find_kv->second;
	else
		return NULL;
	
}

void KV::Set(K k, V v) {
	map<K, V>::iterator find_kv;
	map<K, unsigned int>::iterator find_ktime;
	
	guarded_mutex guard{ mtx_ };//�Դ����mtx_����

	autoremove();//��������map

	find_kv = m_mapKV.find(k);
	//�ҵ�k��λ�ã�����vֵ�Ҹ���ʱ�����
	if (find_kv != m_mapKV.end()) {
		find_kv->second = v;
		m_mapKTime.find(k)->second = GetTickCount();
	}
	//δ�ҵ�k��λ�ã�����֮
	else
	{	//��������СN ���Բ���
		if (count < N) {
			m_mapKV.insert(pair<K,V>(k,v));
			m_mapKTime.insert(pair<K, unsigned int>(k, GetTickCount()));
			count++;
		}
		//���������ﵽN ɾ��ʱ�䳤������
		else
		{
			K del = m_mapKTime.begin()->first;
			unsigned int minTime = m_mapKTime.begin()->second;
			//Ѱ��ʱ����õ�����
			for (find_ktime = m_mapKTime.begin() ; find_ktime != m_mapKTime.end(); find_ktime++) {
				if (find_ktime->second < minTime) {
					del = find_ktime->first;
					minTime = find_ktime->second;
				}
				
			}
			//ɾ��<K,V><K,Time>
			int flagKV = m_mapKV.erase(del);		
			int flagKtime = m_mapKTime.erase(del);
			//����������
			m_mapKV.insert(pair<K, V>(k, v));
			m_mapKTime.insert(pair<K, unsigned int>(k, GetTickCount()));
		}
		
	}
}

void KV::autoremove() {
	unsigned int now_time = GetTickCount();
	for (map<K, unsigned int>::iterator it = m_mapKTime.begin(); it != m_mapKTime.end(); it++) {
		
		if (now_time - it->second > T) {
			m_mapKTime.erase(it);
			m_mapKV.erase(it->first);
			count--;
		}
	}
}
/*
b.  Set��Ѷ�Ӧ�ļ�ֵ�洢���������Kֵ�Ѿ����ڣ���Ḳ��Vֵ��
c.  Get�᷵����K��Ӧ��Vֵ�������������᷵�ؿմ���
d.  ���洢N����¼���������N�����ɾ����������ݣ������ݱ��޸ĵ�ʱ��Ϊ׼����
e.  ���ݳ���Tʱ��û�б��޸ģ��ͻᱻ�Զ�ɾ����
f.  ��Ҫ�����ܸ߶�д�����̰߳�ȫ��
*/