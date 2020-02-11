#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector < pair < long long, long long > > res;

int main() {
	long long T; cin >> T;
	for (long long t = 0; t < T; ++t) {
		long long N, S; cin >> N >> S;
		map < long long, long long > dict;
		bool found = false;
		dict[0] = 0;
		long long sum{ 0 };
		for (long long j = 1; j <= N; j++) {
			int x; cin >> x;
			sum = 1LL * sum + x;
			if (dict.count(sum - S) == 1 && !found) {
				res.push_back({ dict[sum - S] + 1, j });
				found = true;
			}
			else {
				dict[sum] = j;
			}
		}

		if (found == false) {
			res.push_back({ 0,1 });
		}
	}
	for (auto it : res) {
		if (it.first == 0) {
			cout << "-1\n";
		}
		else {
			cout << it.first << " " << it.second << "\n";
		}
	}
	return 0;
}