#include <iostream>
#include <algorithm>

using namespace std;

long long UglyNumber(int n) {
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	long long* arr = new long long[n + 1];
	arr[0] = 1;
	for (int i = 1; i < n; i++) {
		long long mini = min(2LL * arr[i2], min(3LL * arr[i3], 5LL * arr[i5]));
		arr[i] = mini;
		if (mini == arr[i2] * 2) {
			i2++;
		}
		if (mini == arr[i3] * 3) {
			i3++;
		}
		if (mini == arr[i5] * 5) {
			i5++;
		}
	}

	long long aux = arr[n-1];

	delete[] arr;

	return aux;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int n;
		cin >> n;
		cout << UglyNumber(n) << "\n";
	}
	return 0;
}