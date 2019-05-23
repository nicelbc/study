#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
/*leetcode_16
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
			
		if (nums.size() < 3)
			return NULL;

		int minValue = INT_MAX;
		int sum;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int l = i + 1;
			int r = nums.size() - 1;			
			
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] == target) {
					return target;
				}
				else if (nums[i] + nums[l] + nums[r] < target) {					
					if (abs(nums[i] + nums[l] + nums[r] - target) < minValue) {
						sum = nums[i] + nums[l] + nums[r];
						minValue = abs(sum - target);
					}						
					l++;
				}
				else {					
					if (abs(nums[i] + nums[l] + nums[r] - target) < minValue) {
						sum = nums[i] + nums[l] + nums[r];
						minValue = abs(sum - target);
					}						
					r--;
				}
			}
		}
		return sum;
	}
};