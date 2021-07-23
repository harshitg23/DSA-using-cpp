#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int *arr, int n)
{
    int include = arr[0], exclude = 0;
    for(int i=1; i<n; i++)
    {
        int includeNew = exclude + arr[i];
        exclude = max(include, exclude);
        include = includeNew;
    }

    return max(include, exclude);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = findMaxSum(arr, n);
    cout<<ans;
    return 0;
}
