/*
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing,
the missing number is to be found.
*/

#include <iostream>

using namespace std;

void Solve1()
{
    int N;
    cin >> N;

    long long sum1 = N  * (N + 1) / 2;
    long long sum2 = 0;

    for(int i=1; i < N; ++i)
    {
        int x;
        cin >> x;
        sum2 = 1LL * x + sum2;
    }

    cout << sum1 - sum2 << "\n";
}

void Solve2()
{
    int nr = 0;
    int N;
    cin >> N;

    for(int i=1; i < N; ++i)
    {
        int x;
        cin >> x;
        nr = nr ^ x;
    }

    for(int i=1; i<=N; ++i)
    {
        nr = nr ^ i;
    }

    cout << nr << "\n";
}

int main()
 {
	int T;
	cin >> T;
	for(int i=1; i<=T; ++i)
    {
	     Solve2();
	}
	return 0;
}
