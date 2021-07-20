#include<bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M)
{
    int dp[n][m];
    for(int j=m-1; j>=0; j--)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(j == m-1)
            {
                dp[i][j] = M[i][j];
            }
            else if(i == n-1)
            {
                if(i==0) // for row matrix
                    dp[i][j] = M[i][j] + dp[i][j+1];
                else
                    dp[i][j] = M[i][j] + std::max(dp[i-1][j+1], dp[i][j+1]);
            }
            else if(i == 0)
            {

                dp[i][j] = M[i][j] + std::max(dp[i][j+1], dp[i+1][j+1]);
            }
            else
            {
                dp[i][j] = M[i][j] + std::max(dp[i][j+1],(std::max(dp[i-1][j+1], dp[i+1][j+1])));
            }
        }
    }
    int ans = dp[0][0];
    for(int i=1; i<n; i++)
        ans = (ans>dp[i][0] ? ans : dp[i][0]);

    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    int ans = maxGold(n,m,grid);
    cout<<ans;
    return 0;
}
