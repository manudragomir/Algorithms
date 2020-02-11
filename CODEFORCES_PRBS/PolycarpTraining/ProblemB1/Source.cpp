#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int days{ 1 };
	for (auto it : v) {
		if (it >= days) {
			days++;
		}
	}
	cout << days - 1;
	return 0;
}