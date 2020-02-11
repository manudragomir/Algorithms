///ONI 2019 - Clasa aVa - pb. copii
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("copii.in");
ofstream fout("copii.out");

long long CalcDivi(long long nr) {
	long long p, d{ 2 };
	long long prod{ 1 };
	while (nr > 1) {
		p = 0;
		while (nr%d == 0) {
			p++;
			nr /= d;
		}
		if (p){
			prod = prod * (1 + p);
		}
		d++;
	}
	return prod;
}

void Case2(long long nr) {
	long long div = sqrt(nr);
	while (nr % (div*div)) {
		div--;
	}
	cout << div*div << " " << CalcDivi(div*div);
}

int cinci(long long nr) {
	int cnt{ 0 };
	while(nr % 5 == 0){
		cnt++;
		nr /= 5;
	}
	return cnt;
}

long long po(int a, int b) {
	long long res{ 1 };
	for (int i = 1; i <= b; i++) {
		res = res * a;
	}
	return res;
}

int CountDigits(long long nr) {
	int cnt{ 0 };
	do {
		cnt++;
		nr /= 10;
	} while (nr);
	return cnt;
}

void Case1(int X, int K) {
	long long res{ 1 };
	long long mod = po(10, K);
	for (int i = 1; i <= X; i++) {
		int no5 = cinci(i);
		res = (res / (po(2, no5))) % mod;
		res = (res * (i / po(5, no5))) % mod;
	}
	int rez = res % mod;
	int nr_cif = CountDigits(rez);
	for (int i = 1; i <= K - nr_cif; i++) {
		cout << 0;
	}
	cout << rez;
}

int main() {
	int c;
	fin >> c;
	if (c == 1) {
		int X, K;
		fin >> X >> K;
		Case1(X, K);
	}
	else {
		long long Y;
		fin >> Y;
		Case2(Y);
	}
	return 0;
}