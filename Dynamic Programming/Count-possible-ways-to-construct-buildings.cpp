#include<bits/stdc++.h>
using namespace std;

int TotalWays(int N)
{
    // long long int mod = 1000000007;
    int build[N+1];
    int space[N+1];
    build[0] = space[0] = 0;
    build[1] = space[1] = 1;
    for(int i=2; i<=N; i++)
    {
        build[i] = space[i-1] % 1000000007;
        space[i] = (space[i-1] + build[i-1]) % 1000000007;
    }

    long long int total = (space[N] + build[N]) % 1000000007;
    return (total*total) % 1000000007;
}

int main()
{
    int n;
    cin>>n;
    int ans = TotalWays(n);
    cout<<ans;
    return 0;
}
