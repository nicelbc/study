#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {

		string ret = "";
		if (num == 0)
			return ret;		
		vector<string> s({ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" });
		vector<int> value( { 1000,900,500,400,100,90,50,40,10,9,5,4,1 });
		
		for (int i = 0; i < s.size(); i++) {
			while (num >= value[i]) {
				ret += s[i];
				num -= value[i];
			}
		}
		return ret;
	}
};