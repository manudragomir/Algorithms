#include <iostream>
#include <algorithm>

using namespace std;

const int NMax = 5005;
int arr[NMax], BIT[NMax], N, pos[NMax];
int small[NMax], great[NMax];

void update(int value, int index) {
	for (int i = index; i <= N; i += i & (-i)) {
		BIT[i] += value;
	}
}

int getSum(int index) {
	int sum = 0;
	for (int i = index; i > 0; i -= i & (-i)) {
		sum += BIT[i];
	}
	return sum;
}

int search(int nr) {
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == nr) {
			return mid;
		}
		if (arr[mid] < nr) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int main() {
	int inv2 = 0, inv3 = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pos[i];
		arr[i] = pos[i];
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		pos[i] = search(pos[i]);
	}

	for (int i = 1; i <= N; i++) {
		inv2 += getSum(N) - getSum(pos[i]);
		great[i] = getSum(N) - getSum(pos[i]);
		update(1, pos[i]);
	}
	cout << "Number of inversions of 2 is " << inv2 << "\n";

	for (int i = 1; i <= N; i++) {
		BIT[i] = 0;
	}

	for (int i = N; i >= 1; i--) {
		small[i] = getSum(pos[i]);
		update(1, pos[i]);
	}

	for (int i = 1; i <= N; i++) {
		inv3 += small[i] * great[i];
	}

	cout << "Number of inversions of 3 is " << inv3 << "\n";
	return 0;
}