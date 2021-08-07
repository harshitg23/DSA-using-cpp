#include<bits/stdc++.h>
using namespace std;

string longestPalin (string s)
{
    int n = s.length();
    string ans;
    int start=0, end=0;
    bool dp[n][n];
    int max=0;
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0, j=gap; j<n; i++,j++)
        {
            if(gap == 0)
            {
                dp[i][j] = true;
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
            if(gap > max && dp[i][j] == true)
            {
                max = gap;
                start = i;
                end = j;
            }
        }
    }
    for(int i=start; i<=end; i++)
        ans += s[i];
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalin(s);
    return 0;
}
