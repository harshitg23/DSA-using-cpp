#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n+1][W+1];
    dp[0][0] = 0;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i==0)
                dp[i][j] = 0;
            else if(j==0)
                dp[i][j] = 0;
            else if(j>=wt[i-1])
            {
                int rwt = j - wt[i-1];
                if(dp[i-1][rwt]+ val[i-1] > dp[i-1][j])
                    dp[i][j] = dp[i-1][rwt] + val[i-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int n, w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    //inserting the values
    for(int i=0; i<n; i++)
        cin>>val[i];
    //inserting the weights
    for(int i=0; i<n; i++)
        cin>>wt[i];
    cout<<knapSack(w, wt, val, n)<<endl;
    return 0;
}
