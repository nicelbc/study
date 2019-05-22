#include"3sum.h"


int main() {

	vector<vector<int>> ret;
	int test[] = {-1, 0, 1, 2, -1, -4};
	int length = sizeof(test)/sizeof(int);
	//cout << leng << endl;
	vector<int> nums(test,test+length);

	ret =  Solution().threeSum(nums);
	
	Solution().print(ret);

	return 0;
}