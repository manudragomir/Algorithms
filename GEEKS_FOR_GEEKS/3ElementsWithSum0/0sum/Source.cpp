#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.in");

void MethodO3(int n, int v[]) {
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (v[i] + v[j] + v[k] == 0) {
					cout << v[i] << ' ' << v[j] << ' ' << v[k] << '\n';
				}
			}
		}
	}
}

void MethodO2(int n, int v[]) {
	sort(v, v + n);
	for (int i = 0; i < n-1; i++) {
		int left = i + 1;
		int right = n-1;
		while (left < right) {
			int sum = v[i] + v[left] + v[right];
			if (sum == 0) {
				cout << v[i] << ' ' << v[left] << ' ' << v[right] << '\n';
				left++;
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				right--;
			}
		}
	}
}

int main() {
	int n; fin >> n;
	int v[100];
	for (int i = 0; i < n; i++) {
		fin >> v[i];
	}

	MethodO3(n, v);
	MethodO2(n, v);
	return 0;
}