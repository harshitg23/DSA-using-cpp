#include<bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int m)
{
    int j = -1, count = 0, ans = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
            count++;
        while(count > m)
        {
            j++;
            if(arr[j]==0)
                count--;
        }
        int length = i-j;
        if(length > ans)
            ans = length;
    }
    return ans;
}

int main()
{

    int n,m;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cin>>m;
    int ans = findZeroes(arr, n, m);
    cout<<ans;
    return 0;
}
