///Find 10001 prime number
#include <iostream>

using namespace std;

const int Nmax = 1000000;

bool ciur[Nmax];

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
    int cnt = 1, i;
    Ciur();
    for(i=3; cnt < 10001; i+=2)
        if(ciur[i] == 0)
        {
            ++cnt;
        }

    cout << i - 2 << " ";
    return 0;
}
