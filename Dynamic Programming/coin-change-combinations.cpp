#include<bits/stdc++.h>
using namespace std;

    int count(vector<int>arr, int n, int sum )
    {
        vector<int>dp(sum+1,0);
        dp[0] = 1;
        for(int i=0; i<n; i++)
            for(int j=arr[i]; j<sum+1; j++)
                dp[j] += dp[j-arr[i]];

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
