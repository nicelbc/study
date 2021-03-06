// stack_stack_queue.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stack>
#include<iostream>


using namespace std;

class _Queue
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (stack1.size() > 0) {
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		int pop_element = stack2.top();
		stack2.pop();
		return pop_element;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	/*_Queue queue;
	
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	for (int i = 0; i < 6; i++)
		cout << queue.pop() << " ";*/

	return 0;
}


