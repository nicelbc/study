#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
/*leetcode_16
����һ������ n ������������ nums �� һ��Ŀ��ֵ target��
�ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
���磬�������� nums = [-1��2��1��-4], �� target = 1.
�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
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