#include<bits/stdc++.h>
using namespace std;

int scs(string X, string Y)
{
    int m = X.length(), n = Y.length();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j =0; j<=n; j++)
        {
            if(!i)
                dp[i][j] = j;
            else if(!j)
                dp[i][j] = i;
            else if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string x, y;
    cin>>x>>y;
    int ans = scs(x, y);
    cout<<ans;
    return 0;
}
