///CodeForces - Choosing Capital For Treeland
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.in");

const int NMax = (int)2e5+5;
const int inf = 0x3f3f3f3f;
vector < pair < int, pair < int, int > > > G[NMax];
int reds;
int viz[NMax], dist[NMax], color[NMax];

void DFSRoot(int node){
    viz[node] = 1;
    for(auto it: G[node]){
        if(!viz[it.first]){
            DFSRoot(it.first);
            reds += it.second.first;
            color[it.second.second] = it.second.first;
        }
    }
}

int red[NMax], edges[NMax];

void DFS(int node){
    viz[node] = 1;
    for(auto it: G[node]){
        if(!viz[it.first]){
            edges[it.first] = edges[node] + 1;
            red[it.first] = red[node];
            if(color[it.second.second] == 1){
                red[it.first]++;
            }
            DFS(it.first);
        }
    }
}

int main()
{
    int n; fin >> n;
    for(int i=1; i<n; i++){
        int x, y; fin >> x >> y;
        G[x].push_back({y,{0,i}});
        G[y].push_back({x,{1,i}});
    }

    DFSRoot(1);
    int mini = inf;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            viz[j] = 0;
            red[j] = 0;
            edges[j] = 0;
        }

        DFS(i);
        dist[i] = (reds - red[1]) + (edges[1] - red[1]);
        mini = min(mini, dist[i]);
    }

    cout << mini << '\n';
    for(int i=1; i<=n; i++){
        if(dist[i] == mini){
            cout << i << ' ';
        }
    }

    return 0;
}
