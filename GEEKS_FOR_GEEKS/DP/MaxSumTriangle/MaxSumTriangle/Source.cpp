#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	int **m = new int*[n+1];
	for (int i = 1; i <= n; i++) {
		m[i] = new int[n+1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			m[i][j] = m[i][j] + max(m[i + 1][j], m[i + 1][j + 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		delete [] m[i];
	}
	delete [] m;
	return 0;
}