#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.in");

void rotateMatrix(int m[101][101], int n) {
	int ot[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ot[n - j + 1][i] = m[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ot[i][j] << " ";
		}
	}
}

int main()
{
	int T, n, m[101][101];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> m[j][k];
			}
		}
		rotateMatrix(m, n);
		cout << "\n";
	}

	return 0;
}