#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n; cin >> n;
	int* dp = new int[n + 1];
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - dp[dp[i - 1]]] + 1;
	}

	ofstream fout("output.out");
	for (int i = 1; i <= n; i++) {
		fout << dp[i] << " ";
	}
	return 0;
}