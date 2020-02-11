#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.in");

const int NMax = 100005;
vector < int > G[NMax];
int viz[NMax], k;
int adj[NMax];

void DFS(int nod){
    viz[nod] = 1;
    int nodes{1};
    for(auto it: G[nod]){
        if(!viz[it]){
            DFS(it);
            nodes+=adj[it];
        }
    }
    adj[nod] = nodes;
    if(nodes % 2 == 0){
        k++;
        adj[nod] = 0;
    }
}

int main()
{
    int n; fin >> n;
    for(int i=1; i<n; i++){
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    if(n%2){
        cout << "-1";
    }
    else{
        DFS(1);
        cout << k - 1;
    }
    return 0;
}
