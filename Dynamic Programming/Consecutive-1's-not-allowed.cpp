#include<bits/stdc++.h>
using namespace std;

long long countStrings(int n)
{
    long long int mod = 1000000007;
    int ones[n+1], zeros[n+1];
    ones[0] = zeros[0] = 0;
    ones[1] = zeros[1] = 1;
    for(int i=2; i<=n; i++)
    {
        zeros[i] = (zeros[i-1] + ones[i-1]) % mod;
        ones[i]  = zeros[i-1] % mod;
    }
    return (zeros[n]+ones[n])%mod;
}

int main()
{
    int n;
    cin >> n;
    long long int ans = countStrings(n);
    cout << ans <<"\n";
    return 0;
}
