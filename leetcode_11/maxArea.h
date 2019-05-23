#pragma once
#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {

		int l = 0, r = height.size() - 1;
		int maxArea = 0;

		while (l < r) {

			maxArea = max(maxArea, min(height[l], height[r])*(r - l));
			
			if (height[l] < height[r])
				l++;
			else
				r--;
		}
		
		return maxArea;
	}
};