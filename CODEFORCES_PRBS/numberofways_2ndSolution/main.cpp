#include <fstream>
#include<iostream>

using namespace std;

const int NMax = 500005;
ifstream fin("input.in");
int v[NMax];

int main()
{
    int n; fin >> n;
    long long sum{0};
    for(int i=0;i<n;++i){
        fin >> v[i];
        sum = 1LL*sum + v[i];
    }

    if(sum%3){
        cout << 0;
    }
    else{
        long long ss = sum/3;
        long long res{0}, cnt{0};
        long long currSum{0};
        for(int i=0; i<n-1; ++i){
            currSum = 1LL*currSum+v[i];
            if(currSum == 2*ss){
                res = 1LL*res + cnt;
            }
            if(currSum == ss){
                cnt = 1LL*cnt + 1;
            }
        }
        cout << res;
    }


    return 0;
}
