#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int N, int arr[], int sum)
{
    bool dp[N+1][sum+1];
    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0 and j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
            else if(j==0)
                dp[i][j] = true;
            else
            {
                if(dp[i-1][j] == true)
                        dp[i][j] = true;
                else
                {
                    int val = arr[i-1];
                    if(val <= j)
                        dp[i][j] = dp[i-1][j-val];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
          //  cout<<dp[i][j];
        }
        //cout<<endl;
    }
    return dp[N][sum];
}

int main()
{
    int n,sum;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>sum;
    bool ans = isSubsetSum(n,arr,sum);
    cout<<ans;
    return 0;
}
