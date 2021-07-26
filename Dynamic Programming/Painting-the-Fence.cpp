#include<bits/stdc++.h>
using namespace std;
long long countWays(int n, int k)
{
    if(n==1)
        return k;
    int m = 1000000007;
    long long same = k*1;
    long long diff = k* (k-1);
    long long total = same + diff;
    for(int i=3; i<=n; i++)
    {
        same = diff * 1;
        diff = (total * (k-1))%m;
        total = (same + diff)%m;
    }

    return total%m;
}
int main()
{
    int n,k;
    cin>>n>>k;
    long long ans = countWays(n,k);
    cout<<ans;
    return 0;
}
