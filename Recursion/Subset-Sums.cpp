#include<bits/stdc++.h>
using namespace std;

void func(int i, int sum, vector<int> &arr, int n, vector<int> &ans)
{
    if(i == n)
    {
        ans.push_back(sum);
        return;
    }
    func(i+1, sum + arr[i], arr,n, ans);
    func(i+1, sum, arr, n, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{

    vector<int> ans;
    func(0, 0, arr, N, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> ans = subsetSums(arr, n);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    return 0;
}
