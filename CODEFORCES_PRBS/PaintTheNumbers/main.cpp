#include <iostream>
#include <algorithm>

using namespace std;

int el[105];
int v[105];
int nrElems = 0;

void Search(int x){
    bool found{false};
    for(int i=1; i<=nrElems && !found; i++){
        if(x % v[i] == 0){
            found = true;
        }
    }

    if(found == false){
        v[++nrElems] = x;
    }
}

int main()
{
    int n; cin >> n;

    for(int i=1; i<=n; i++){
        cin >> el[i];
    }

    sort(el + 1, el + n + 1);

    for(int i=1; i<=n; i++){
        Search(el[i]);
    }

    cout << nrElems;
    return 0;
}
