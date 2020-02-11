#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* v = new int[n+1];
    v[1] = 1;
    v[2] = 2;
    v[3] = 2;
    for(int i=1; i<=min(n,3); i++){
        cout << v[i] << " ";
    }
    int cnt = 4, i = 3;
    while(cnt <= n){
        int j=1;
        while(j<=v[i] && cnt<=n){
            if(cnt<=n){
                v[cnt] = i;
            }
            cnt++;
            cout << i << " ";
            j++;
        }
        i++;
    }
    delete[] v;
    return 0;
}
