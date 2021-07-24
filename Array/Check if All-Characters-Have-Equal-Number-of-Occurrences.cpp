#include <bits/stdc++.h>
using namespace std;

    bool areOccurrencesEqual(string s)
    {
        vector<int> arr(26,0);
        int max = 0;
        for(int i=0; i<s.length(); i++)
        {
            arr[s[i]-97]++;
            if(arr[s[i]-97]>max)
                max = arr[s[i]-97];
        }
        for(int i=0; i<26; i++)
        {
            if(arr[i]!=max && arr[i]!=0)
                return false;
        }
        return true;
    }

int main()
{
    string s;
    cin>>s;
    cout<<areOccurrencesEqual(s);

    return 0;
}
