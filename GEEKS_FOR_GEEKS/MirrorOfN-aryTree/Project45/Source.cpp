#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int Check(int n, vector < queue < int > >& t1, vector < stack < int > >& t2) {
	for (int i = 1; i <= n; i++) {
		queue<int>& cont1 = t1[i];
		stack<int>& cont2 = t2[i];
		while (!cont1.empty() && !cont2.empty()) {
			if (cont1.front() != cont2.top()) {
				return 0;
			}
			cont1.pop();
			cont2.pop();
		}

		if (!cont1.empty() || !cont2.empty()) {
			return 0;
		}
	}
	return 1;
}


int main() {
	int T;
	cin >> T;
	//creeaza 20 de cozi v[i] e coada cu indicele i
	for (int i = 0; i < T; i++) {
		int V, E;
		cin >> V >> E;

		vector < queue < int > > t1(V+1);
		vector < stack < int > > t2(V+1);
		for (int k = 0; k < E; k++) {
			int n1, n2;
			cin >> n1 >> n2;
			t1[n1].push(n2);
		}

		for (int k = 0; k < E; k++) {
			int n1, n2;
			cin >> n1 >> n2;
			t2[n1].push(n2);
		}

		cout << Check(V, t1, t2) << "\n";
	}
	return 0;
}