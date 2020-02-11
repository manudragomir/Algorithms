#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int NMax = 100;

class BIT
{
private:
	int* arr;
	int len;
	int internSum(int index) {
		//index = index + 1;
		int sum = 0;
		while (index > 0) {
			sum += arr[index];
			index -= (index & (-index));
		}
		return sum;
	}
public:
	int getSum(int st, int dr) {
		return internSum(dr) - internSum(st - 1);
	}
	void update(int element, int index) {
	//	index = index + 1;
		while (index <= len) {
			arr[index] += element;
			index += (index & (-index));
		}
	}
	BIT(int len) : len{ len } {
		arr = new int[len + 1];
		for (int i = 0; i < len; i++)
			arr[i] = 0;
	};
	BIT(int* v, int n) {
		arr = new int[n + 1];
		len = n;
		for (int i = 0; i < len; i++)
			arr[i] = 0;

		for (int i = 0; i < n; i++) {
			update(v[i], i+1);
		}
	}
	~BIT()
	{
		delete[] arr;
	}
};

int binSearch(int arr[], int el, int len) {
	int st = 0, dr = len;
	int mij;
	while (st < dr) {
		mij = (st + dr) / 2;
		if (arr[mij] == el) {
			return mij;
		}
		if (el < arr[mij]) {
			dr = mij - 1;
		}
		else {
			st = mij + 1;
		}
	}
	return st;
}

int main() {
	ifstream fin("input.in");
	int n, v[NMax];
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> v[i];
	}

	//redim
	int copyV[NMax];
	for(int i=0; i<n; i++){
		copyV[i] = v[i];
	}

	sort(copyV, copyV + n);
	for (int i = 0; i < n; i++) {
		v[i] = binSearch(copyV, v[i], n) + 1;
	}

	int cnt_inversions = 0;
	BIT aib{ n };
	for (int i = n - 1; i >= 0; i--) {
		cnt_inversions += aib.getSum(0, v[i] - 1);
		aib.update(1, v[i]);
	}

	cout << cnt_inversions << "\n";
	return 0;
}
