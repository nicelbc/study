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
	map<K,V> m_mapKV;//存储K—V
	map<K,unsigned int> m_mapKTime;//存储K-Time	
	typedef unique_lock<std::mutex> guarded_mutex;
	std::mutex mtx_;//互斥量

public:
	V Get(K);
	void Set(K, V);
	void autoremove();//超过时间T删除

};

V KV::Get(K k){
	map<K, V>::iterator find_kv;
	
	guarded_mutex guard{ mtx_ };//对传入的mtx_ 上锁

	autoremove();//更新两个map

	find_kv = m_mapKV.find(k);
	if (find_kv != m_mapKV.end())
		return find_kv->second;
	else
		return NULL;
	
}

void KV::Set(K k, V v) {
	map<K, V>::iterator find_kv;
	map<K, unsigned int>::iterator find_ktime;
	
	guarded_mutex guard{ mtx_ };//对传入的mtx_上锁

	autoremove();//更新两个map

	find_kv = m_mapKV.find(k);
	//找到k的位置，更新v值且更新时间参数
	if (find_kv != m_mapKV.end()) {
		find_kv->second = v;
		m_mapKTime.find(k)->second = GetTickCount();
	}
	//未找到k的位置，插入之
	else
	{	//数据条数小N 可以插入
		if (count < N) {
			m_mapKV.insert(pair<K,V>(k,v));
			m_mapKTime.insert(pair<K, unsigned int>(k, GetTickCount()));
			count++;
		}
		//数据条数达到N 删除时间长的数据
		else
		{
			K del = m_mapKTime.begin()->first;
			unsigned int minTime = m_mapKTime.begin()->second;
			//寻找时间最久的数据
			for (find_ktime = m_mapKTime.begin() ; find_ktime != m_mapKTime.end(); find_ktime++) {
				if (find_ktime->second < minTime) {
					del = find_ktime->first;
					minTime = find_ktime->second;
				}
				
			}
			//删除<K,V><K,Time>
			int flagKV = m_mapKV.erase(del);		
			int flagKtime = m_mapKTime.erase(del);
			//插入新数据
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
b.  Set会把对应的键值存储下来，如果K值已经存在，则会覆盖V值；
c.  Get会返回与K对应的V值，如果不存在则会返回空串；
d.  最多存储N条记录，如果超过N，则会删除最早的数据（以数据被修改的时间为准）；
e.  数据超过T时间没有被修改，就会被自动删除；
f.  需要尽可能高读写，且线程安全。
*/