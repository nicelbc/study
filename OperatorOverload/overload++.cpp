#include<iostream>

using namespace std;

class Time {

private:
	int hours; //0-23
	int minutes; //0-59
public:
	//构造函数
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

	//显示时间
	void display() {
		cout << "H:" << hours << "M:" << minutes << endl;
	}

	//重载前缀++
	Time operator++() {
		++minutes;
		if (minutes >= 60) {
			hours += 1;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}
	// 重载后缀递增运算符（ ++ ）
	Time operator++(int)
	{
		// 保存原始值
		Time T(hours, minutes);
		// 对象加 1
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		// 返回旧的原始值
		return T;
	}

};

int main()
{
	Time T1(11, 59), T2(10, 40);

	++T1;                // T1 加 1
	T1.display();		// 显示 T1
	++T1;				// T1 再加 1
	T1.display();		// 显示 T1

	Time t = T2++;		// T2 加 1
	t.display();
	T2.display();       // 显示 T2
	
	return 0;
}