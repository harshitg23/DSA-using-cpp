#include<bits/stdc++.h>
using namespace std;

int fibonaccie(int n)
{
    if(n<=1)
        return n;
    cout<<"n == "<<n<<"\n";
    return fibonaccie(n-1)+ fibonaccie(n-2);
}
int fibonaccie_DP(int n)
{
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++)
    {
        cout<<"i == "<<i<<"\n";
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
int main()
{
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    cout<<fibonaccie(n);
    cout<<"\nFibonacci using DP \n";
    cout<<fibonaccie_DP(n);
    return 0;
}
