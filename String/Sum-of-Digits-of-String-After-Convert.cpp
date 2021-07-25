#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k)
{
    string convert;
    int sum = 0;
    for(int i=0; i<s.length(); i++)
        convert+= to_string(s[i]-96);

    for(int i=0; i<convert.length(); i++)
        sum += convert[i]-'0';
    k--;
    while(k>0)
    {
        int sum1=0;
        while(sum>0)
        {
            sum1 += sum%10;
            sum = sum/10;
        }
        sum = sum1;
        k--;
    }
    return sum;
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    int ans = getLucky(s,k);
    cout<<ans;
    return 0;
}
