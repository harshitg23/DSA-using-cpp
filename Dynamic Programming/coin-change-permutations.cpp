#include<bits/stdc++.h>
using namespace std;

int count(vector<int>arr, int n, int sum )
{
    vector<int>dp(sum+1,0);
    dp[0] = 1;
    for(int i=1; i<sum+1; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j] <= i)
                dp[i] += dp[i-arr[j]];
        }
    }
    return dp[sum];
}

int main()
{
    int sum,n;
    cin>>sum>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = count(arr,n,sum);
    cout<<ans;
    return 0;
}
