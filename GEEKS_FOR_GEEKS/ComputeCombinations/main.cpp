#include <iostream>

using namespace std;

const int mod = 666013;

void invmod(long long a, long long b, long long &x, long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }

    long long x0, y0, q=a/b;

    invmod(b, a%b, x0, y0);
    x=y0;
    y=x0-y0*q;

}

long long modr(long long nom)
{
    long long x, y;
    invmod(nom, mod, x, y);

    if(x<=0)
        x=mod+x%mod;

    return x;
}

long long combinari(int n, int k)
{
    long long f1=1, f2=1;

    for(int i=n-k+1; i<=n; ++i)
        if(i%mod)
            f1 = ((f1%mod) * (i%mod)) % mod;

    for(int i=1; i<=k; ++i)
       if(i%mod)
            f2 = ((f2%mod) * (i%mod)) % mod;

   f1 = ((f1%mod)*(modr(f2)%mod)) % mod;

    return f1;
}

int main()
{
    int n,k;

    cin>>n>>k;

    cout<<combinari(n,k);
    return 0;
}
