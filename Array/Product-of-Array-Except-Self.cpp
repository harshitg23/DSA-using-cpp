#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
    {
        int product = 1, flag = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                flag++;
            else
                product *= nums[i];
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(flag == 1)
            {
                if(nums[i]!=0)
                    nums[i] = 0;
                else
                    nums[i] = product;
            }
            else if(flag>1)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = product / nums[i];
            }
        }
        return nums;
    }

    int main()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        vector<int>ans = productExceptSelf(nums);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        return 0;
    }
