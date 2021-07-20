#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int dp[m][n];

    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i == m-1 and j == n-1)
            {
                dp[i][j] = grid[i][j];
            }
            else if(i == m-1)
            {
                dp[i][j] = grid[i][j] + dp[i][j+1];
            }
            else if(j == n-1)
            {
                dp[i][j] = grid[i][j] + dp[i+1][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + std::min(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i=0; i<m; i++)
    {
        vector<int> v;
        for(int j=0; j<n; j++)
        {
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        grid.push_back(v);
    }
    int ans = minPathSum(grid);
    cout<<ans;
    return 0;
}
