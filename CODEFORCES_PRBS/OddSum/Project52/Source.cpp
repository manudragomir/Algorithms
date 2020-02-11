#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	long long sum{ 0 };
	int minImparePozitiv = (int)2e9;
	int maxImpareNegativ = -(int)2e9;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x > 0) {
			sum = 1LL * sum + (long long)x;
		}
		
		if (x % 2 && x > 0) {
			minImparePozitiv = min(minImparePozitiv, x);
		}

		if (x % 2 && x < 0) {
			maxImpareNegativ = max(maxImpareNegativ, x);
		}
	}
	
	if (sum % 2 == 1) {
		cout << sum;
	}
	else {
		cout << max(sum + maxImpareNegativ, sum - minImparePozitiv);
	}
	return 0;
}