#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b[n+2];
    b[0]=1;
    b[n+1]=1;
    for(int i=1;i<n+1;i++)
    b[i]=a[i-1];
    int dp[n+2][n+2];
    memset(dp,0,sizeof(dp));
    for(int len=1;len<=n;len++)
    {
        for(int left=1;left<=n-len+1;left++)
        {
            int right=left+len-1;
            for(int k=left;k<=right;k++)
            {
                dp[left][right]=max(dp[left][right],dp[left][k-1]+
                                                    b[left-1]*b[k]*b[right+1]+
                                                    dp[k+1][right]);
            }
        }
    }
    // for(int i=0;i<=n+1;i++)
    // {
    //     for(int j=0;j<=n+1;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[1][n];
}
