#include<bits/stdc++.h>
using namespace std;
long long numberOfWays(long long N)
{
    int mod = 1000000007;
    if(N<=2)
        return N;
    long long dp[N+1];
    dp[0]=1;
    dp[1]= 1;
    for(int i=2; i<=N; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1])%mod;
    }

    return dp[N];
}
int main()
{
    long long n;
    cin>>n;
    long long ans = numberOfWays(n);
    cout<<ans;
    return 0;
}
