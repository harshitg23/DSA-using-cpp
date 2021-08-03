#include<bits/stdc++.h>
using namespace std;

int count(int nums[], int n, int target)
{
    int ans = 0;
    sort(nums, nums+n);
    for(int i=0; i<n-2; i++)
    {
        int left = i+1, right = n-1;
        while(left<right)
        {
            int current = nums[i] + nums[left] + nums[right];
            if(current > target)
                right--;
            else
            {
                ans += right - left;
                left++;
            }
        }
    }
    return ans;
}
int countTriplets(int nums[], int n, int L, int R)
{
    int ans = count(nums, n, R)-count(nums, n, L-1);
    return ans;
}

int main()
{
    int n, L, R;
    cin>>n;
    int nums[n];
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cin>>L>>R;
    int ans = countTriplets(nums, n, L, R);
    cout<<ans;
    return 0;
}
