#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("mostenire.in");
ofstream fout("mostenire.out");

struct Fiu {
	int galbeni;
	int nrcrt;
	int saci;
	int age;
};

int main() {
	int N, K;
	fin >> N >> K;
	int* v = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		fin >> v[i];
	}
	
	int maxim = -(int)2e9;
	int ii, jj;
	for (int i = 1; i <= N; ++i) {
		int mezin = 0;
		for (int j = i; j <= N; ++j) {
			mezin += v[j];
			int frati = 0;
			
			int partial = 0;
			for (int k = 1; k < i; k++) {
				partial += v[k];
				if (partial >= mezin) {
					partial = 0;
					frati++;
				}
			}

			partial = 0;
			for (int k = j + 1; k <= N; k++) {
				partial += v[k];
				if (partial >= mezin) {
					partial = 0;
					frati++;
				}
			}
			
			if (frati >= K - 1 && mezin > maxim) {
				maxim = mezin;
				ii = i;
				jj = j;
			}
		}
	}
	vector < Fiu > res;
	int partial = 0, nrcrt = 1, saci = 1;
	for (int k = 1; k < ii; k++) {
		partial += v[k];
		if (partial >= maxim) {
			Fiu f;
			f.galbeni = partial;
			f.nrcrt = nrcrt++;
			f.saci = k - saci + 1;
			saci = k + 1;
			res.push_back(f);
			partial = 0;
		}
	}

	Fiu f;
	int galbeni = 0;
	for (int i = ii; i <= jj; i++) {
		galbeni += v[i];
	}
	f.galbeni = galbeni;
	f.nrcrt = nrcrt++;
	f.saci = jj - ii + 1;
	res.push_back(f);

	partial = 0;
	saci = jj + 1;
	for (int k = jj + 1; k <= N; k++) {
		partial += v[k];
		if (partial >= maxim) {
			Fiu f;
			f.galbeni = partial;
			f.nrcrt = nrcrt++;
			f.saci = k - saci + 1;
			saci = k + 1;
			res.push_back(f);
			partial = 0;
		}
	}

	sort(res.begin(), res.end(), [&](Fiu a, Fiu b) {
		return a.galbeni > b.galbeni;
	});

	int cnt = 1;
	for (auto& it : res) {
		it.age = cnt++;
	}

	sort(res.begin(), res.end(), [&](Fiu a, Fiu b) {
		return a.nrcrt < b.nrcrt;
	});


	fout << maxim << '\n';
	for (auto it : res) {
		fout << it.age << " " << it.saci << "\n";
	}
	delete[] v;
	return 0;
}