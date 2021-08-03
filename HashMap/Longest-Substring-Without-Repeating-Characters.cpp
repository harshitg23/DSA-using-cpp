#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int res = 0, i = 0;
    unordered_map<char, int> ump;
    for(int j=0; j<n; j++)
    {
        if(ump.find(s[j]) != ump.end())
            i = max(i, ump[s[j]] + 1);
        ump[s[j]] = j;
        res = max(res, j-i+1);
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    int ans = lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}
