#include <iostream>

using namespace std;

int main() {
	int n, x, y; cin >> n >> x >> y;
	char s[2 * 100000 + 1];
	cin.get();
	cin.getline(s, n+1);
	int cnt{ 0 };
	for (int i = 0; i < x; i++) {
		if(i == y && s[n-(i+1)] != '1'){
			++cnt;
		}
		
		if (i != y && s[n-(i+1)] != '0') {
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}