#include <iostream>

using namespace std;

int isPalindrom(int nr)
{
    int nr_nou = 0;
    int save = nr;

    while(save)
    {
        nr_nou = nr_nou * 10 + save % 10;
        save /= 10;
    }

    return (nr_nou == nr);
}

int main()
{
    int maxi = 0, imax, jmax;
    for(int i=999;i>=100;i--)
    {
        for(int j=i; j>=100; j--)
            if(isPalindrom(i*j))
            {
                if(i*j > maxi)
                {
                    maxi = max(i*j, maxi);
                    imax = i;
                    jmax = j;
                }

            }
    }
    cout << imax << " " << jmax;
    return 0;
}
