///Compute the number of possibilities such that if you divide
///the array in three contiguous sequences the sum is the same for each sequence.
#include <iostream>
#include <fstream>

using namespace std;

const int NMax = 500005;
ifstream fin("input.in");

int v[NMax], start[NMax];

int main()
{
    int n; fin>>n;
    for(int i=1; i<=n; i++){
        fin >> v[i];
    }

    int sum1, sum2, sum3, cnt{0};

    start[n] = v[n];
    for(int i=n-1; i>=1; i--){
        start[i] = start[i+1] + v[i];
    }

    if(start[1] % 3 != 0){
        cout << 0;
        return 0;
    }
    sum1 = v[1];
    for(int j=2; j<=n-1; j++){
        sum2 = v[j];
        sum3 = start[j+1];
        int k = j+1;
        while(k<=n){
            if(sum1 == sum2 && sum2 == sum3){
                ++cnt;
            }
            sum2 += v[k];
            sum3 -= v[k];
            ++k;
        }
        sum1 += v[j];
    }

    cout << cnt << "\n";

    return 0;
}
