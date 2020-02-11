#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int cmmdc(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

pair < int, int > simplify(int a, int b) {
	int x = cmmdc(a, b);
	return { a / x, b / x };
}

int getNumberOfIntersections(int N, vector < pair < int, pair < int, int > > > lines) {
	map < pair < int, int >, set < int > > slopes;

	int total_lines{ 0 };
	int total_inters{ 0 };
	for (auto line : lines) {
		int a = line.first;
		int b = line.second.first;
		int c = line.second.second;
		pair < int, int > slope = simplify(b, a);
		if (!slopes[slope].count(c)) {
			slopes[slope].insert(c);
			total_lines++;
			total_inters += total_lines - slopes[slope].size();
		}
	}

	return total_inters;
}

int main() {
	int N;
	ifstream fin("input.in");
	ofstream fout("output.out");
	fin >> N;
	vector < pair < int, pair < int, int > > > lines(N);

	for (int i = 0; i < N; ++i) {
		fin >> lines[i].first >> lines[i].second.first >> lines[i].second.second;
	}

	cout << getNumberOfIntersections(N, lines);

	return 0;
}