#include<bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int>& arr)
	{
	    int n = arr.size();
	    int dp[n+1];
	    int tsum = 0;
	    for(int i=0; i<n; i++)
	    {
	        int sum = 0;
	        for(int j = 0; j<i; j++)
	        {
	            if(arr[j] < arr[i])
	            {
	                if(dp[j]>sum)
	                   sum = dp[j];
	            }
	        }
	        dp[i] = arr[i] + sum;
	        if(dp[i] > tsum)
	            tsum = dp[i];
	    }
	    return tsum;
	}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    int ans = maxSumIS(nums);
    cout<<ans;
    return 0;
}
