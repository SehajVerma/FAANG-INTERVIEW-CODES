#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    int count=n;
    for(int len=2;len<=n;len++)
    {
        for(int left=0;left<n-len+1;left++)
        {
            int right = left+len-1;
            if(len==2)
            {
                if(s[left]==s[right]){
                 dp[left][right]=1;
                }
            }
            else
            {
                if(s[left]==s[right])
                dp[left][right]=dp[left+1][right-1];
            }
            if(dp[left][right])
            count++;
        }
    }
    cout<<count;
}
