#include<bits/stdc++.h>
using namespace std;

int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> dp(W+1, 0);
    dp[0] = 0;
    for(int i=1; i<W+1; i++)
    {
        int max = 0;
        for(int j=0; j<N; j++)
        {
            if(wt[j] <= i)
            {
                int rWt = i - wt[j];
                int rWtVal = dp[rWt];
                int tWtVal = rWtVal + val[j];

                max = (tWtVal>max) ? tWtVal : max;
            }
        }
        dp[i] = max;
    }
    return dp[W];
}

int main()
{
    int n, w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    //inserting the values
    for(int i=0; i<n; i++)
        cin>>val[i];
    //inserting the weights
    for(int i=0; i<n; i++)
        cin>>wt[i];
    cout<<knapSack(n, w, val, wt)<<endl;
    return 0;
}
