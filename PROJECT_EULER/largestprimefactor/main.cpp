n#include <iostream>
#include <cmath>

using namespace std;

const int Nmax = 100;

bool ciur[Nmax];
int primes[Nmax];

void Ciur()
{
    ciur[1] = 1;
    for(int i=4; i<=Nmax; i+=2)
        ciur[i] = 1;

    for(int i=3; i<=Nmax; i+=2)
    {
        if(ciur[i] == 0)
        {
            for(int j=i+i; j<=Nmax; j+=i)
                ciur[j] = 1;
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    /*
    Ciur();
    int k = 0;
    for(int i=1; i<=n; i++)
    {
        if(ciur[i] == 0)
            primes[++k] = i;
    }

    k = 1;
    int maxi = 0;
    */

    int maxi = 0;
    int d = 2;
    while(n>1)
    {
        int po = 0;
        while(n % d == 0)
        {
            n/=d;
            po++;
        }

        if(po)
            maxi = d;
        d++;
    }

    cout << maxi;

    return 0;
}
