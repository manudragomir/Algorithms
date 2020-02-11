#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int mod = (int)1e9 + 7;
const int NMax = 105;
const int DMax = 10115;
ifstream fin("tairos.in");
ofstream fout("tairos.out");

long long arb[NMax]; /// arb[i] - noduri la inaltimea i in arborele initial
long long nodes[DMax]; /// nodes[i] - noduri la inaltimea i in arborele infinit

long long arbfr[NMax]; /// arbfr[i] - nr frunze la inaltimea i in arborele initial
long long fr[DMax]; /// fr[i] - nr de frunze la inaltimea i in arborele infinit

vector < int > G[NMax];
int viz[NMax], treeHeight{-1};

void DFS(int node, int lvl){
    viz[node] = 1;
    arb[lvl]++; nodes[lvl]++;
    treeHeight = max(treeHeight, lvl);

    if(G[node].size() == 1 && node != 1){
        fr[lvl]++;
        arbfr[lvl]++;
    }
    else{
        for(auto it: G[node]){
            if(!viz[it]){
                DFS(it, lvl+1);
            }
        }
    }
}

int main()
{
    int N, D; fin >> N >> D;
    for(int i = 0; i < N-1; i++){
        int x, y; fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    DFS(1, 0);

    /*
    for(int i=1; i<=treeHeight; i++){
        cout << "arb" << i << ' ' << arb[i] << '\n';
        cout << "fr" << i << ' ' << fr[i] << '\n';
        cout << "nodes" << i << ' ' << nodes[i] << '\n';
    }*/

    for(int i=1; i<=D; i++){
        for(int h=1; h<=treeHeight; h++){
            nodes[i+h] = ((nodes[i+h] % mod) + (((arb[h] % mod) * (fr[i] % mod)) % mod)) % mod;
            fr[i+h] =    ((fr[i+h] % mod) + (((arbfr[h] % mod) * (fr[i] % mod)) % mod)) % mod;
        }
    }

    /*
    for(int i=1; i<=D; i++){
        cout << '\n';
        cout << "At level " << i << ' ' << "we have:\n";
        cout << "nodes: " << nodes[i] << '\n';
        cout << "fr:" << fr[i] << '\n';
    }*/

    fout << nodes[D];
    return 0;
}
