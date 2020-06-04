#include<iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		switch (str[i]) {
		case '(': s.push(str[i]); break;
		case ')': s.pop(); break;
		case '0': return s.size();
		default: break;
		}
	}	
}

void main() {

	string s = "(()(()((()(0)))))";
	cout << solution(s);
}