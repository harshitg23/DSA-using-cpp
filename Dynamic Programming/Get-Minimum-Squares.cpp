#include<bits/stdc++.h>
using namespace std;

int MinSquares(int n)
{
    if(n<4)
        return n;
    vector<int> dp(n+1, 1e5);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 1; i*i<=n; i++)
    {
        for(int j=0; i*i+j<=n; j++)
        {
            dp[i*i +j] = min(dp[i*i+j], 1+dp[j]);
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int ans = MinSquares(n);
    cout << ans <<"\n";
    return 0;
}
