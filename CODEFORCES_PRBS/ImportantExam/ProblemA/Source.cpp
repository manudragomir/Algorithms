#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, ap[5];
	char ans[1005][1005];
	int points[1005];

	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		cin.getline(ans[i], m+1);
	}

	for (int i = 0; i < m; i++) {
		cin >> points[i];
	}

	long long sum{ 0 };

	for (int j = 0; j < m; j++) {
		ap[0] = ap[1] = ap[2] = ap[3] = ap[4] = 0;

		for (int i = 0; i < n; i++) {
			ap[ans[i][j] - 'A']++;
		}

		int maxi{ -1 };
		for (int k = 0; k < 5; k++) {
			maxi = max(maxi, ap[k]);
		}

		sum += 1LL * maxi * points[j];
	}

	cout << sum;
	return 0;
}