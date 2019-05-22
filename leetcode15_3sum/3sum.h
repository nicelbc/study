#pragma once
//leetcode-15
/*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
/*思路：利用双指针，必须先对数组排序，每次固定i的位置，利用连个指针指向开始start = i + 1 ；
end = length - 1； 的位置，根据结果来移动start 和 end；
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

			if (i != 0 && nums[i] == nums[i - 1])//避免重复元素
				continue;

			while (start < end) {

				if (nums[start] + nums[end] + nums[i] == 0) {//三者之和为0
					ret.push_back({ nums[i],nums[start],nums[end] });
					start++;//判断之后的是否也满足
					end--;

					while (start < end && nums[start] == nums[start - 1])//避免start重复
						start++;
					while (start < end && nums[end] == nums[end + 1])//避免end重复
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