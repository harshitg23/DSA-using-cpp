#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> mp;
    int maj = 0, ele = 0;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
        if(mp[nums[i]] > maj)
        {
            maj = mp[nums[i]];
            ele = nums[i];
        }
    }
    return ele;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = majorityElement(arr);
    cout<<ans;
    return 0;
}
