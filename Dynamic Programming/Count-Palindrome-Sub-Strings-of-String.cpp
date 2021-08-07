#include<bits/stdc++.h>
using namespace std;

int CountPS(string s)
{
    int n = s.length();
    bool dp[n][n];
    int ans=0;
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0, j=gap; j<n; i++,j++)
        {
            if(gap == 0)
            {
                dp[i][j] = true;
                continue;
            }
            else if(gap == 1)
            {
                if(s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if(dp[i+1][j-1] == true && s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            if(dp[i][j])
                ans++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<CountPS(s);
    return 0;
}
