#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

void Solve(char s[], int K) {
	vector <int> digits[10];
	queue <int > Q;
	char res[31];
	int noDigits = strlen(s);
	int vis[31];

	for (int i = 0; i < noDigits; i++) {
		vis[i] = 0;
		digits[s[i] - '0'].push_back(i);
	}
	//4551711527
	int changes = 0;
	int currPosition = 0;
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < digits[i].size(); j++) {
			if (i != s[currPosition]-'0' && changes < K) {
				vis[currPosition] = 1;
				res[currPosition] = i + '0';
				if (currPosition < digits[i][j]) {
					Q.push(digits[i][j]);
				}
				changes++;
				currPosition++;
			}
			else if (i == s[currPosition]-'0') {
				res[currPosition] = i + '0';
				currPosition++;
			}
			else {
				if (vis[digits[i][j]] == 1) {
					int pos = Q.front();
					Q.pop();
					while (pos < currPosition) {
						pos = Q.front();
						Q.pop();
					}
					res[pos] = i + '0';
				}
				else {
					res[digits[i][j]] = i + '0';
				}
			}
		}
	}

	res[noDigits] = 0;
	cout << res << "\n";
}

int main()
{
	int T, K;
	char s[31];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> K;
		cin.get();
		cin.getline(s, 31);
		Solve(s, K);
	}
	return 0;
}