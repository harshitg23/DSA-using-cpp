#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    int n =nums.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i+1, right = n-1;
        while(left<right)
        {
            int current = nums[i] + nums[left] + nums[right];
            if(current == 0)
            {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[left]);
                v.push_back(nums[right]);
                st.insert(v);
                left++;
                right--;
            }
            else if(current < 0)
                left++;
            else
                right--;
        }
    }

    for(auto x : st)
        ans.push_back(x);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    vector<vector<int>> v = threeSum(nums);
    for(int i=0; i<v.size(); i++)
    {
        cout<<"["<<v[i][0]<<", "<<v[i][1]<<", "<<v[i][2]<<"]"<<endl;
    }
    return 0;
}
