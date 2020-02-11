#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    long long sum{0};
    for(int i=2; i<n; i++){
        sum = 1LL * sum + i * (i+1);
    }
    cout << sum;
    return 0;
}
