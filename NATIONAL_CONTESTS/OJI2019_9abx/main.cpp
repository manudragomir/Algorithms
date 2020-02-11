/*
 * Problema abx (OJI 2019)
 * Complexitate: O(N*log^2(M))
 * Autor: Lucian Bicsi
 */

#include <bits/stdc++.h>

using namespace std;

const long long kInf = 2e18 + 10;
long long max_base[80];

long long Power(long long b, int e) {
	long long r = 1;
	for (int i = 0; i < e; ++i) {
		if (1.0L * r * b > 6e18)
			return kInf;
		r *= b;
	}
	return r;
}

long long Root(long long x, int ex) {
	long long b = 1, e = max_base[ex], ans = 1;
	while (b <= e) {
		long long m = (b + e) / 2;
		if (Power(m, ex) <= x) {
			ans = m;
			b = m + 1;
		}
		else e = m - 1;
	}
	return ans;
}


int main() {
//	ifstream cin("abx.in");
	//ofstream cout("abx.out");

	int n; long long m; cin >> n >> m;
	cout << 1e5 << " ";
	return 0;
	assert(1 <= n && n <= 1e5);
	assert(10 <= m && m <= 1e18);

	for (int ex = 2; ex <= 64; ++ex) {
		max_base[ex] = kInf;
		max_base[ex] = Root(m, ex);
	}


	long long max_diff = 0;
	for (int i = 0; i < n; ++i) {
		long long x; cin >> x;
		long long ans = 1;
		assert(1 <= x && x <= m);

		for (int ex = 2; ex <= 64; ++ex) {
			long long root = Root(x, ex);
			long long c1 = Power(root, ex), c2 = Power(root + 1, ex);
			if (c1 <= m && make_pair(abs(c1 - x), c1) <
				make_pair(abs(ans - x), ans)) ans = c1;
			if (c2 <= m && make_pair(abs(c2 - x), c2) <
				make_pair(abs(ans - x), ans)) ans = c2;
		}

		cout << ans << '\n';
		max_diff = max(max_diff, abs(ans - x));
	}

	cerr << "MAXIMUM DIFFERENCE: " << max_diff << endl;
}
