#include <iostream>
#include <algorithm>

using namespace std;

int MCM(int N, int p[]) {
	int m[105][105];
	for (int i = 1; i <= N; i++) {
		m[i][i] = 0;
	}
	
	for (int L = 1; L <= N - 1; L++) {
		for (int i = 1; i <= N - L; ++i) {
			int j = i + L;
			int mini = (int)2e9;
			for (int k = i; k < j; ++k) {
				mini = min(mini, m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k]);
			}
			m[i][j] = mini;
		}
	}
	return m[1][N];
}

int main() {
	int T; cin >> T;
	for(int t=0; t<T; ++t){
		int n; cin >> n;
		int* p = new int[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		cout << MCM(n - 1, p) << "\n";
		delete[] p;
	}
	return 0;
}