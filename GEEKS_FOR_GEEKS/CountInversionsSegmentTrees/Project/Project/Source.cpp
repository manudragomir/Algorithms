#include <iostream>

using namespace std;

class AI
{
	int* ai;
public:
	AI(int n) {
		ai = new int[8 * n + 1];
		for (int i = 1; i < 8 * n + 1; i++) {
			ai[i] = 0;
		}
	}
	void add(int nr, int st, int dr, int poz) {
		if (st == dr) {
			//exista un numar cu valoare nr
			ai[poz] = 1;
			return;
		}
		int mij = (st + dr) / 2;
		if (nr <= mij) {
			add(nr, st, mij, 2 * poz);
		}
		else {
			add(nr, mij + 1, dr, 2 * poz + 1);
		}
		ai[poz] = ai[2 * poz] + ai[2 * poz + 1];
	}
	int query(int st, int dr, int currSt, int currDr, int poz) {
		//daca sunt in interval pot aduna
		if (currSt >= st && currDr <= dr) {
			return ai[poz];
		}
		int mij = (currSt + currDr) / 2;
		int nr1, nr2;
		nr1 = 0;
		nr2 = 0;
		if (mij >= st) {
			nr1 = query(st, dr, currSt, mij, 2 * poz);
		}
		if (mij < dr) {
			nr2 = query(st, dr, mij + 1, currDr, 2 * poz + 1);
		}
		return nr1 + nr2;
	}
	~AI() {
		delete[] ai;
	}
};

int main() {
	//[i; j) cate numere sunt mai mari egale decat i si mai mici strict decat j
	int n; cin >> n;
	AI ai(5);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		count += ai.query(x + 1, n, 1, n, 1);
		ai.add(x, 1, n, 1);
	}
	cout << count;
	return 0;
}