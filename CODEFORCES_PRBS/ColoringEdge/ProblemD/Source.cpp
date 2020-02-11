#include <iostream>
#include <vector>

using namespace std;

const int NMax = 5005;

vector < pair < int, int > > G[NMax];
int color[NMax];
int ver[NMax];
bool cycle{ false };

void DFS(int node){
	ver[node] = 1;
	for (auto nbr: G[node]) {
		int next = nbr.first;
		int edge = nbr.second;
		if (ver[next] == 0) {
			color[edge] = 1;
			DFS(next);
		}
		else if(ver[next] == 1){
			color[edge] = 2;
			cycle = true;
		}
		else {
			color[edge] = 1;
		}
	}
	ver[node] = 2;
}




int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		G[x].push_back(make_pair(y, i));
	}

	for (int i = 0; i < N; i++) {
		if (ver[i] == 0) {
			DFS(i);
		}
	}

	if (cycle == true) {
		cout << "2\n";
	}
	else {
		cout << "1\n";
	}

	for (int i = 0; i < M; i++) {
		cout << color[i] << " ";
	}
	return 0;
}