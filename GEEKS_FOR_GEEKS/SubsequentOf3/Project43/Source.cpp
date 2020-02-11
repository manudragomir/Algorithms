#include <iostream>
#include <vector>

using namespace std;

void find3Numbers(int* arr, int n) {
	int* great = new int[n];
	int* small = new int[n];
	for (int i = 0; i < n; i++) {
		great[i] = -1;
		small[i] = -1;
	}

	int minIndex, maxIndex;
	minIndex = 0;
	for (int i = 1; i < n; i++) {
		if (arr[minIndex] >= arr[i]) {
			minIndex = i;
		}
		else {
			small[i] = minIndex;
		}
	}

	maxIndex = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[maxIndex] <= arr[i]) {
			maxIndex = i;
		}
		else {
			great[i] = maxIndex;
		}
	}

	vector<int>subs;
	for (int i = 0; i < n; i++) {
		if (great[i] != -1 && small[i] != -1) {
			subs.push_back(arr[small[i]]);
			subs.push_back(arr[i]);
			subs.push_back(arr[great[i]]);
		}
	}

	for (auto it : subs) {
		cout << it << " ";
	}
	delete[] great;
	delete[] small;
}

int main()
{
	int arr[] = { 12, 11, 10, 5, 6, 2, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	find3Numbers(arr, n);
	return 0;
}