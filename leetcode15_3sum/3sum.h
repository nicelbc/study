#pragma once
//leetcode-15
/*����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

����, �������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
/*˼·������˫ָ�룬�����ȶ���������ÿ�ι̶�i��λ�ã���������ָ��ָ��ʼstart = i + 1 ��
end = length - 1�� ��λ�ã����ݽ�����ƶ�start �� end��
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> ret;

		if (nums.size() == 0)
			return ret;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			int start = i + 1;
			int end = nums.size() - 1;

			if (i != 0 && nums[i] == nums[i - 1])//�����ظ�Ԫ��
				continue;

			while (start < end) {

				if (nums[start] + nums[end] + nums[i] == 0) {//����֮��Ϊ0
					ret.push_back({ nums[i],nums[start],nums[end] });
					start++;//�ж�֮����Ƿ�Ҳ����
					end--;

					while (start < end && nums[start] == nums[start - 1])//����start�ظ�
						start++;
					while (start < end && nums[end] == nums[end + 1])//����end�ظ�
						end--;
				}
				else if (nums[start] + nums[end] + nums[i] < 0) {
					start++;
				}
				else {
					end--;
				}
			}
		}
		return ret;

	}

	void print(vector<vector<int>> ret) {
		for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++) {
			for (int i = 0; i<(*it).size(); i++) {
				cout << (*it)[i] << " ";
			}
			cout << endl;
		}
	}
};