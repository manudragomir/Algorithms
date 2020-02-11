#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("mostenire.in");
ofstream fout("mostenire.out");

bool Far(int x, int y, int a){
    if(abs(a-x) > abs(a-y)){
        return true;
    }
    return false;
}

struct Fiu{
    int galbeni;
    int nrcrt;
    int saci;
    int age;
};

int main()
{
    int N, K, mezin = 2e9;
    long long sum = 0;
    int* v = new int[N+1];
    fin >> N >> K;
    for(int i=0; i<N; ++i){
        fin >> v[i];
        sum = 1.0L * sum + v[i];
    }

    int medie = sum / K;
    vector < Fiu > res;
    int curr = v[0];
    int galbeni, nrcrt{1}, saci{1};
    v[N] = 2e9;
    for(int i=1; i<=N; ++i){
           if(Far(curr + v[i], curr, medie) == true){
                mezin = min(mezin, curr);
                Fiu f;
                f.galbeni = curr;
                f.nrcrt = nrcrt++;
                f.saci = i - saci + 1;
                saci = i + 1;
                curr = v[i];
                res.push_back(f);
           }
           else{
                curr += v[i];
           }
    }

    sort(res.begin(), res.end(), [&](Fiu a, Fiu b){
         return a.galbeni < b.galbeni;
         });

    int cnt=1;
    for(auto it: res){
        it.age = cnt++;
    }
    /*
    sort(res.begin(), res.end(), [&](Fiu a, Fiu b){
         return a.nrcrt < b.nrcrt;
         });
         */


    cout << mezin << '\n';
    for(auto it: res){
        cout << it.age << " " << it.saci << "\n";
    }
    delete[] v;
    return 0;

}
