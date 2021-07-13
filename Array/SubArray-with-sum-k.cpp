#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
        int ans = 0, temp = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i=0; i<N; i++)
        {
            temp += arr[i];
            if(mp[temp - k] > 0)
                ans += mp[temp - k];
            mp[temp]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
