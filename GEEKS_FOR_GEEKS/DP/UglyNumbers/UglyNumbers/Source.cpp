#include <iostream>

using namespace std;

int getUglyNumber(int n) {
	int* arr = new int[n + 1];
	arr[0] = 1;
	int index2, index3, index5;
	index2 = index3 = index5 = 1;

	for (int i = 1; i <= n; i++) {

	}

	int number = arr[n];
	delete[] arr;

	return number;
}

int main() {
	int n;
	cin >> n;
	cout << getUglyNumber(n);
	return 0;
}