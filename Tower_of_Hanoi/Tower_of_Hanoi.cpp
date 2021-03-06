// Tower_of_Hanoi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<windows.h>

using namespace std;

void move(int n, char from, char depend_on, char to) {
	if (n == 1)
		cout << from << "--" << 1 << "--" << to << endl;//递归出口 只有一个盘子 直接from——>to
	else {
		move(n - 1, from, to, depend_on);//把n-1个盘子从from放到depend_on
		cout << from << "--" << n  << "--" << to << endl;//把第n个直接从from->to
		move(n - 1, depend_on, from, to);//把之前n-1个从depend_on放入to

	}
}

int main()
{
	double start, end;
	start = GetTickCount();
	move(6, 'A', 'B', 'C');
	end = GetTickCount();
	cout << end - start << " ms" << endl;
    return 0;
}

