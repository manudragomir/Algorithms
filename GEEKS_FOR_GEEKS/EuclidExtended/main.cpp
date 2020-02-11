#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

pair < long long, long long > euclid_extins(long long x, long long y)
{
    if(y==0)
    {
        return {1,0};
    }

    auto  p = euclid_extins(y, x%y);
    long long d = x/y;
    return {p.second, p.first-d*p.second};
}

long long divi(long long a, long long b)
{
    long long r;
    while(b)
    {
       r=a%b;
       a=b;
       b=r;
    }

    return a;
}

int main()
{
    //freopen("euclid3.in", "r", stdin);
    //freopen("euclid3.out", "w", stdout);
    long long n;
    scanf("%lld", &n);

    for(long long i=1; i<=n; ++i)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long d=divi(a,b);
        pair < long long, long long > per;
        per = euclid_extins(a,b);

        if(c%d ==0)
            cout <<per.first * c / d << " " << per.second * c / d << "\n";
        else
            cout << 0 << " " <<0 << "\n";

    }

    return 0;
}
