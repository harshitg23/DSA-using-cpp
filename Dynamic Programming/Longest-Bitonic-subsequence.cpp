#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int>nums)
{
    int n = nums.size();

    int dp[n];
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                if(dp[j] > sum)
                    sum = dp[j];
            }
        }
        dp[i] = 1+sum;
    }

    int dp1[n];
    for(int i=n-1; i>=0; i--)
    {
        int sum = 0;
        for(int j=n-1; j>i; j--)
        {
            if(nums[j] < nums[i])
            {
                if(dp1[j] > sum)
                    sum = dp1[j];
            }
        }
        dp1[i] = 1+sum;
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] + dp1[i] -1 > ans)
            ans = dp[i] + dp1[i] -1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    int ans = LongestBitonicSequence(nums);
    cout<<ans;
    return 0;
}
