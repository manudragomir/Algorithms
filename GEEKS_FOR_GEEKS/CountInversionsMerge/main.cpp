#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int CountInversionsBrute(int* v, int N)
{
    int cnt = 0;

    for(int i=1; i < N; i++)
    {
        for(int j=i+1; j <= N; j++)
            if(v[i] > v[j])
                ++cnt;
    }

    return cnt;
}

long long MergeInversions(int* v, int i, int mij, int j)
{
    int cntinv = 0;

    int* arr = new int[mij-i+2];
    int* arr2 = new int[j-mij+2];
    int* rez = new int[j-i+2];

    int cnt_i = 0, cnt_j = 0;
    for(int k = i; k<=mij; k++)
        arr[++cnt_i] = v[k];

    for(int k = mij+1; k<=j; k++)
        arr2[++cnt_j] = v[k];

    int sti = 1, stj = 1, k = 0;
    while(sti <= cnt_i && stj <=cnt_j)
    {
        if(arr[sti] <= arr2[stj])
        {
            rez[++k] = arr[sti++];
            cntinv += stj - 1;
        }

        else
        {
            rez[++k] = arr2[stj++];
        }
    }

    while(sti <= cnt_i)
    {
        rez[++k] = arr[sti++];
        cntinv += cnt_j;
    }

    while(stj <= cnt_j)
    {
        rez[++k] = arr2[stj++];
    }

    for(int it = 1; it <= k; it++)
        v[i+it-1] = rez[it];

    delete[] arr;
    delete[] arr2;
    delete[] rez;
    return cntinv;
}

long long CountInversionsEf(int* v, int i, int j)
{
    if(i==j)
    {
        return 0;
    }

    if(j - i == 1)
    {
        if(v[i] > v[j])
        {
            swap(v[i], v[j]);
            return 1;

        }

        return 0;
    }

    int mij = i + (j-i)/2;

    long long cnt1 = CountInversionsEf(v, i, mij);
    long long cnt2 = CountInversionsEf(v, mij+1, j);
    long long actual_inversions = MergeInversions(v, i, mij, j);

    return cnt1 + cnt2 + actual_inversions;

}

int main()
{
    int v[65580];

    ifstream fin("input.in");
    ofstream fout("input.out");

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> v[i];

   // cout << CountInversionsBrute(v, N);

    cout << CountInversionsEf(v, 1, N);

    return 0;
}
