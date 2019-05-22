#include<iostream>
#include"LetterCombinationsPhoneNumber.h"
using namespace std;


int main() {
	
	string s = "236";
	Solution solution;

	vector<string> ret;

	ret = solution.letterCombinations(s);
	solution.print(ret);
	
	
	
	return 0;
}

