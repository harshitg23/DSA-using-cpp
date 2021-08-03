#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = 1000000000;

        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int left = i+1, right = nums.size()-1;
            while(left<right)
            {
                int current = nums[i] + nums[left] + nums[right];
                if(abs(1LL*target - current) < abs(1LL*target - sum))
                {
                    sum = current;
                }
                if(current == target)
                {
                    left++;right--;
                }
                else if(current < target)
                    left++;
                else
                    right--;

            }
        }
        return sum;
    }

int main()
{
    int n, target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    int ans = threeSumClosest(nums, target);
    cout<<ans;
    return 0;
}
