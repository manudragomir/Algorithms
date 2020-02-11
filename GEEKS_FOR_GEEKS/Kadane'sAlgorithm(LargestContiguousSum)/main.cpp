#include <iostream>

using namespace std;

void Solve()
{
    int N, v[1005];

    cin >> N;

    for(int i=1; i<=N; ++i)
        cin >> v[i];

    int maxsum, actsum;
    maxsum = actsum = v[1];

    for(int i=2; i<=N; ++i)
    {
        actsum = max(actsum + v[i], v[i]);
        //la pasul actual, merg mai departe cu suma mai mare
        //care e ori elementul actual, ori suma + elem actual
        maxsum = max(maxsum, actsum);
    }

    cout << maxsum << "\n";
}

int main()
 {
	int T;
	cin >> T;
	for(int i=1; i<=T; ++i)
	{
	    Solve();
	}
	return 0;
}
