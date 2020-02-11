#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int sum{ 0 };

		b /= 2;
		if (h >= c) {
			int mini = min(b, p);
			sum += mini * h;

			b -= mini;
			mini = min(b, f);
			sum += mini * c;
		}
		else {
			int mini = min(b, f);
			sum += mini * c;

			b -= mini;
			mini = min(b, p);
			sum += mini * h;
		}

		cout << sum << "\n";
	}
	return 0;
}