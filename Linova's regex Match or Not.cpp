#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    string pattern;
    cin>>text;
    cin>>pattern;
    int m = text.size();
    int n = pattern.size();
    if(m==0 || n==0)
    cout<<"0";
    else{
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(pattern[i-1]=='*')
        dp[0][i]=dp[0][i-2];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((text[i-1] == pattern[j-1]) || pattern[j-1]=='.')
            dp[i][j]=dp[i-1][j-1];
            else
            {
                if(pattern[j-1]=='*')
                {
                    if(dp[i][j-2])    // 0 occurances 
                    dp[i][j]=1;
                    else
                    {
                        if(pattern[j-2]==text[i-1] || pattern[j-2]=='.')
                           dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
    }
    // for(int i=0;i<=m;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[m][n];
    }
}
