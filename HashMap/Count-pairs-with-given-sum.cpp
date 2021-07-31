#include<bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int> arr, int n, int k)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    for(int i=0; i<n; i++)
    {
        ans += mp[k-arr[i]];
        if(k - arr[i] == arr[i])
        {
            ans--;
        }
    }
    return ans/2;
}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = getPairsCount(arr, n, k);
    cout<<ans;
    return 0;
}
