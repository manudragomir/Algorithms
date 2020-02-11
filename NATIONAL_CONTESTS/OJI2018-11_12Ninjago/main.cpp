#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

const int Nmax = 31201;

ifstream fin("ninjago.in");
ofstream fout("ninjago.out");

vector < pair < int, char* > > G[Nmax];
vector < pair < int, int > > G2[Nmax];
queue < int > Q;

int N, M;
int viz[Nmax];

int check(char* s)
{
    int cnt = 0;
    for(int i=0; i<4; i++)
        if(s[i] == 'E')
            cnt++;;

    return cnt;
}

void BFS()
{
    viz[1] = 1;
    Q.push(1);

    while(!Q.empty())
    {
        int nod = Q.front();
        Q.pop();
        for(auto it: G[nod])
        {
            if(viz[it.first] == 0 && check(it.second) == 0)
            {
                viz[it.first] = 1;
                Q.push(it.first);
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++)
        if(viz[i] == 1)
            cnt++;

    fout << cnt;
}

priority_queue < pair < int, int > > Qu;
int dist[Nmax];

void Task2(int t)
{
    Qu.push({0,1}); // cost, valoare
    for(int i=1; i<=N; i++)
        dist[i] = 0x3f3f3f3f;
    dist[1] = 0;
    int coridoare = 0;
    int euri = 0;
    int nodes = 0;

    while(!Qu.empty())
    {

        int nod = Qu.top().second;
        Qu.pop();

        if(viz[nod])
            continue;

        viz[nod] = 1;

        for(auto it: G2[nod])
        {
            if(viz[it.first] == 0 && dist[it.first] > it.second)
            {
                dist[it.first] = it.second;
                Qu.push({-it.second, it.first});
            }
        }
    }

    int cost = 0;

    for(int i=1; i<=N; i++)
    {
        if(dist[i] > 625)
            coridoare++;

        euri += dist[i] / 625;
        cost += dist[i] % 625;
    }

    if(t==2)
    {
        fout << coridoare << "\n" << euri;
    }

    else if(t==3)
        fout << cost;

}

int Aduna(char str[5])
{
    int val = 0;
    int po = 1;
    for(int i=0; i<4; i++)
    {
        if(str[i] == 'E')
            val += 625;
        else
            val += po * (str[i] - 'A' + 1);

        po*=5;
    }

    return val;
}

int main()
{
    int t;
    fin >> t;
    fin >> N >> M;

    for(int i=1; i<=M; i++)
    {
        int nod1, nod2;
        char* str;
        str = new char[10];
        fin >> nod1 >> nod2 >> str;
        fin.get();
        G[nod1].push_back({nod2,str});
        G[nod2].push_back({nod1,str});

        int val = Aduna(str);
        G2[nod1].push_back({nod2,val});
        G2[nod2].push_back({nod1,val});
    }

    if(t==1)
        BFS();
    else
        Task2(t);

    return 0;
}
