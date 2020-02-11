#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int Coef(int n, int k) {
	if (k == 1) {
		return n;
	}
	if (n == k || k == 0) {
		return 1;
	}
	return Coef(n - 1, k - 1) + Coef(n - 1, k);
}

int CoefDP(int n, int k) {
	int C[300 + 1][300 + 1];
	int i, j;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}

	return C[n][k];
}

int CoefMemDP(int n, int k) {
	int* C = new int[k+1];
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}
	C[0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = min(i, k); j > 0; j--) {
			if (j == 0 || j == i) {
				C[j] = 1;
			}
			else {
				C[j] += C[j - 1];
			}
		}
	}
	int res = C[k];
	delete[] C;
	return res;
}



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		//cout << Coef(n, k) % mod << "\n";
		cout << CoefMemDP(n, k) % mod << "\n";
	}
	return 0;
}