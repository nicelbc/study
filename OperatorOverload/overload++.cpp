#include<iostream>

using namespace std;

class Time {

private:
	int hours; //0-23
	int minutes; //0-59
public:
	//���캯��
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		hours = h;
		minutes = m;
	}
	~Time()
	{

	}

	//��ʾʱ��
	void display() {
		cout << "H:" << hours << "M:" << minutes << endl;
	}

	//����ǰ׺++
	Time operator++() {
		++minutes;
		if (minutes >= 60) {
			hours += 1;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}
	// ���غ�׺����������� ++ ��
	Time operator++(int)
	{
		// ����ԭʼֵ
		Time T(hours, minutes);
		// ����� 1
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		// ���ؾɵ�ԭʼֵ
		return T;
	}

};

int main()
{
	Time T1(11, 59), T2(10, 40);

	++T1;                // T1 �� 1
	T1.display();		// ��ʾ T1
	++T1;				// T1 �ټ� 1
	T1.display();		// ��ʾ T1

	Time t = T2++;		// T2 �� 1
	t.display();
	T2.display();       // ��ʾ T2
	
	return 0;
}