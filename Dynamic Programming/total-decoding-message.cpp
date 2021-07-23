#include<bits/stdc++.h>
using namespace std;

int CountWays(string str)
{
    int n = str.length();
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++)
    {
        if(str[i-1] == '0' && str[i] == '0')
            dp[i] = 0;
        else if(str[i-1] == '0' && str[i] != '0')
             dp[i] = dp[i-1];
        else if(str[i-1] != '0' && str[i] == '0')
        {
            if(str[i-1] == '1' || str[i-1] == '2')
                (i>=2 ? dp[i] =  dp[i-2] : dp[i] =  1);
            else
                dp[i] = 0;
        }
        else
        {
            if(str[i-1] == '1' ||(str[i-1] == '2' && str[i] < '7'))
            {
                (i>=2 ?  dp[i] = dp[i-1] + dp[i-2] :  dp[i] = dp[i-1] + 1);
            }
            else
                dp[i] = dp[i-1];

        }
    }
    return dp[n-1];
}

int main()
{
    string n;
    cin>>n;
    int ans = CountWays(n);
    cout<<ans;
    return 0;
}
