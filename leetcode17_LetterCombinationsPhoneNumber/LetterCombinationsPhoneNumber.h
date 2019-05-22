#pragma once
#include<iostream>
#include<vector>





using namespace std;

/*����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��



ʾ��:

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/
class Solution {
public:
	vector<string> letterCombinations(string digits) {

		vector<string> ret;

		if (digits.size() == 0)
			return ret;
		
		ret.push_back("");
		vector<string> dict(10);
		dict[2] = "abc";
		dict[3] = "def";
		dict[4] = "ghi";
		dict[5] = "jkl";
		dict[6] = "mno";
		dict[7] = "pqrs";
		dict[8] = "tuv";
		dict[9] = "wxyz";

		for (int i = 0; i < digits.size(); i++) {
			int size = ret.size();
			for (int j = 0; j < size; j++) {
				string cur = ret[0];
				ret.erase(ret.begin());
				for (int k = 0; k < dict[digits[i] - '0'].size(); k++)
					ret.push_back(cur + dict[digits[i] - '0'][k]);
			}
		}

		return ret;

	}

	void print(vector<string> s) {
		for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
			for (int i = 0; i < (*it).size(); i++){
				cout<<(*it)[i];
			}
			cout << " ";
		}
			
		cout << endl;
	}
};