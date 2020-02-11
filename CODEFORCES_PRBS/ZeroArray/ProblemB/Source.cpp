i #include <iostream>

using namespace std;

int main() {
	unsigned long long n, x, sum{ 0 }, dig{ 0 }, max{ 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		dig = (dig + x%2) % 2;

		if (x > max) {
			sum += max;
			max = x;
		}

		else {
			sum += x;
		}
	}

	if (max <= sum && dig == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
