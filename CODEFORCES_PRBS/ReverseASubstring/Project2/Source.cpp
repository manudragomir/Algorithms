#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	char* s = new char[n + 1];
	cin.get();
	cin.getline(s, n + 1);

	bool not_found = true;
	for (int i = 0; i < n-1 && not_found; i++) {
		if (s[i] > s[i + 1]) {
			cout << "YES\n";
			cout << i + 1 << " " << i + 2;
			not_found = false;
		}
	}
	if (not_found == true) {
		cout << "NO";
	}
	delete[] s;
	return 0;
}