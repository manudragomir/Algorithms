#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int q, k, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> k;
		vector < int > v(n);
		int odds{ 0 };
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			if (v[j] % 2) {
				++odds;
			}
		}
		if (odds < k || odds % 2 != k % 2) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			int cnt{ 1 };
			for (int j = 0; j < n && cnt<k; j++) {
				if (v[j] % 2 == 1) {
					cout << j + 1 << " ";
					cnt++;
				}
			}
			cout << n << "\n";
		}
	}
	return 0;
}