#include<iostream>
#include<vector>

using namespace std;

void bulidHeap(vector<int> &arr);
void heapify(vector<int> &arr, int count, int i);
void sortHeap(vector<int> &arr);

void  buildHeap(vector<int> &arr){

	int count = arr.size() - 1;

	for (int i = count / 2; i >= 1; i--)
		heapify(arr,count, i);
}

void heapify(vector<int> &arr,int count,  int i) {
	
	while (2 * i <= count) {
		int j = 2 * i;
		if (j + 1 <= count && arr[j] < arr[j + 1])
			j += 1;
		if (arr[i] < arr[j]) {
			swap(arr[i], arr[j]);
			i = j;
		}
		else
			break;
		

	}
}

void sortHeap(vector<int> &arr) {

	int n = arr.size() - 1;

	for (int i = n; i >= 1; i--) {
		swap(arr[i], arr[1]);
		heapify(arr, i - 1, 1);
	}
}

int main() {

	vector<int> arr{ 0, 40, 52, 23, 5 ,18};

	buildHeap(arr);
	sortHeap(arr);

	for (int i = 1; i < arr.size(); i++)
		cout << arr[i] << endl;
	return 0;
}