#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("input.in");

const int NMax = 2*(int)1e5+5;
const int inf = 0x3f3f3f3f;

vector < pair < int, int > > G[NMax];
int cost[NMax], n, mini{inf};

int Prim(int nod){
    priority_queue < pair < int, int > > Q;

    bool viz[NMax];
    int ct[NMax];
    for(int i=1; i<=n; i++){
        viz[i] = false;
        ct[i] = inf;
    }

    Q.push({0,nod});
    ct[nod] = 0;
    int aici{0};
    while(!Q.empty()){
        int next = Q.top().second;
        int cost = Q.top().first;
        Q.pop();
        if(viz[next]){
            continue;
        }
        viz[next] = true;
        aici+=cost;
        if(aici>mini){
            return mini+1;
        }
        for(auto it: G[next]){
            if(!viz[it.first] && ct[it.first]>=it.second){
                ct[it.first] = it.second;
                Q.push({-it.second, it.first});
            }
        }
    }

    int reverses{0};
    for(int i=1; i<=n; i++){
            if(ct[i]){
                reverses++;
            }
    }
    return reverses;
}

int main()
{
    fin >> n;
    for(int i=0; i<n-1; i++){
        int x, y; fin >> x >> y;
        G[x].push_back({y,0});
        G[y].push_back({x,1});
    }

    for(int i=1; i<=n; i++){
        cost[i] = Prim(i);
        mini = min(mini, cost[i]);
    }

    cout << mini << '\n';
    for(int i=1; i<=n; i++){
        if(cost[i] == mini){
            cout << i << ' ';
        }
    }
    return 0;
}
