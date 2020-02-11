#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("conexidad.in");
ofstream fout("conexidad.out");

const int NMax = 105;
const int inf = 0x3f3f3f3f;
vector < int > G[NMax];
vector < pair < int, int > > edges;
int viz[NMax], maxi{-inf};
int extra[NMax], lua[NMax];

struct Componenta{
    vector < int > comp;
};

auto comp = [](Componenta a, Componenta b){
    int luaA{0}, luaB{0};
    for(auto it: a.comp){
        luaA += lua[it];
    }

    for(auto it: b.comp){
        luaB += lua[it];
    }

    return luaA < luaB;
};


void DFS(int node, int conn, Componenta& c){
    viz[node] = 1;
    c.comp.push_back(node);
    for(auto it: G[node]){
        if(!viz[it]){
            DFS(it, conn, c);
        }
    }
}

void Union(Componenta& c1, Componenta& c2){
    for(auto it: c2.comp){
        c1.comp.push_back(it);
    }
    auto compa = [&](int x, int y){return extra[x]<extra[y];};
    sort(c1.comp.begin(), c1.comp.end(), compa);
}

int main()
{
    int n, m; fin >> n >> m;
    for(int i=1; i<=m; i++){
        int x, y; fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int conn{1};
    vector < Componenta > v;
    for(int i=1; i<=n; i++){
        if(!viz[i]){
            Componenta c;
            DFS(i, conn, c);
            v.push_back(c);
        }

        lua[i] = 1;
    }

    sort(v.begin(), v.end(), comp);
    int cnt{0};
    while(v.size() > 1){
            auto c1 = v.at(0);
            auto c2 = v.at(v.size() - 1);

            int nod1 = c1.comp[0];
            int nod2 = c2.comp[0];
            extra[nod1]++;
            extra[nod2]++;

            lua[nod1] = 0;
            lua[nod2] = 0;

            maxi = max(maxi, extra[nod2]);
            maxi = max(maxi, extra[nod1]);

            Union(c1,c2);
            v.pop_back();
            v[0] = c1;

            sort(v.begin(), v.end(), comp);
            edges.push_back({nod1,nod2});
    }

    fout << maxi << '\n';
    fout << edges.size() << '\n';
    for(auto edge: edges){
        fout << edge.first << ' ' << edge.second << '\n';
    }

    return 0;
}
