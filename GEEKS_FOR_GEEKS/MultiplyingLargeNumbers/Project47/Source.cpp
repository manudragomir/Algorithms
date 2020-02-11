#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string multiplyStrings(string, string);

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		string a;
		string b;
		cin >> a >> b;

		cout << multiplyStrings(a, b) << endl;
	}

}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below function */
string multiplyStrings(string s1, string s2) {
	int cnt = 0;

	int n = (int)s1.length();
	int m = (int)s2.length();
	if (n == 0 || m == 0) {
		return "0";
	}

	if (s1.at(0) == '-') {
		cnt++;
		s1.erase(s1.begin());
	}
	if (s2.at(0) == '-') {
		cnt++;
		s2.erase(s2.begin());
	}

	n = (int)s1.length();
	m = (int)s2.length();
	vector < char > res(n + m, '0');

	int carry, pos = 0, i, j;
	for (i = n - 1; i >= 0; i--) {
		int dig = (int)(s1.at(i) - '0');
		carry = 0;
		for (j = m - 1; j >= 0; j--) {
			int toDig = (int)(s2.at(j) - '0');
			pos = i + j + 1;
			int currDig = (int)(res.at(pos) - '0');
			int x = currDig;
			currDig = (dig*toDig + carry + currDig) % 10;
			carry = (dig*toDig + carry + x) / 10;
			res.at(pos) = (char)('0' + currDig);
		}
		if(carry && pos)
			res.at(pos-1) = (char)('0' + carry);
	}

	while (res.at(0) == '0') {
		res.erase(res.begin());
	}

	string s(res.begin(), res.end());

	if (cnt == 1) {
		s.insert(s.begin(), '-');
	}
	return s;
}
