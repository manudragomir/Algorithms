#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int kt = 13;
ifstream fin("in.txt");
ofstream fout("out.txt");

bool nozeros(char* s, int st, int fin)
{
    for(int i=st; i<=fin; i++)
    {
        if(s[i] == '0')
            return false;
    }

    return true;
}

long long functi(char* s, int st_poz)
{
    long long prod = 1;
    for(int i=st_poz; i < st_poz + kt; i++)
    {
        prod =  1LL * prod * (s[i]-'0');
    }
}

int main()
{
    char s[1005];
    fin>>s;

    int sum = 0;
    int max_sum = 0;
    int st_poz = 0;
    long long max_pr = 0;
    max_sum = sum;

    for(int i=0; i<kt; i++)
    {
        sum += s[i]-'0';

    }

    max_sum = sum;

    for(int i=kt; i<1000; i++)
    {
        sum-=s[i-kt]-'0';
        sum+=s[i]-'0';
        long long pr = functi(s,i-kt);
        if(pr > max_pr)
            max_pr = pr;
        if(max_sum <= sum && nozeros(s, i-kt+1, i))
        {
            max_sum = sum;
            st_poz = i - kt + 1;
        }
    }

    fout << max_pr;



    return 0;
}
