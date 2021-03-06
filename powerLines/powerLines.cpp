// powerLines.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

vector<string> input();//接收输入
bool isElectricLines(vector<string> & lines);//判断函数

void main()
{	
	vector<string> lines;

	lines = input();
		
	if (isElectricLines(lines))
		cout << "OK" << endl;
	else
		cout << "Not OK" << endl;    
}

bool isElectricLines(vector<string> & lines) {
	map<char, int> charNumMap;
	//统计每个字符出现的次数 放入map中
	for (vector<string>::iterator iter = lines.begin(); iter != lines.end(); iter++) {
		for (int i = 0; i < 2; i++) {
			map<char, int>::iterator find_char;
			find_char = charNumMap.find(iter[0][i]);

			if (find_char != charNumMap.end())
				find_char->second++;
			else
				charNumMap.insert(pair<char, int>(iter[0][i], 1));
		}
	}

	//只有一种字符 必然符合条件
		if (charNumMap.size() == 1)
			return true;
	//>=2种字符
		else if (charNumMap.size() >= 2) {
			int odd = 0;
			int even = 0;
			//统计每个字符出现的次数（奇数偶数）
			for (map<char, int>::iterator iter = charNumMap.begin(); iter != charNumMap.end(); iter++) {
				if (iter->second % 2 == 0)
					even++;
				else
					odd++;
			}
			//cout << "odd :" << odd << endl << "even :" << even << endl;
			//只有两个奇数 符合条件
			if (odd == 2)
				return true;
			//全部为偶数个
			else if (odd == 0) {
				//每个字符两端不能相同
				for (vector<string>::iterator iter = lines.begin(); iter != lines.end(); ++iter)
					if (iter[0][0] == iter[0][1])
						return false;
				return true;				
			}
			else
				return false;
		}
		return false;

	
}

vector<string> input() {
	int N;
	cout <<" input the lines N : "<< endl;
	cin >> N;
	cout << "input " << N << " strings:" << endl;
	vector<string> lines;
	string str;

	while (N) {
		
		cin >> str;
		lines.push_back(str);
		N--;
	}

	return lines;
}