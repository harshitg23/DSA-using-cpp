#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    int omax = 0;
    int dp[n];
    for(int i=0; i<n; i++)
    {
        int max = 0;
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                if(dp[j] > max)
                    max = dp[j];
            }
        }
        dp[i] = 1 + max;
        if(dp[i] > omax)
            omax = dp[i];
    }
    return omax;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    int ans = lengthOfLIS(nums);
    cout<<ans;
    return 0;
}
