#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int maxi = nums[0], mini = nums[0], temp = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]<0)
            swap(mini, maxi);
        maxi = max(nums[i], maxi*nums[i]);
        mini = min(nums[i], mini*nums[i]);

        if(maxi>temp)
            temp = maxi;
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    int ans = maxProduct(nums);
    cout<<ans;
    return 0;
}
