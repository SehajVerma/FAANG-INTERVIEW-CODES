#include <bits/stdc++.h>
using namespace std;
#define n 4
int dp[16][n]; //dp[2^n][n]
int dist[n][n];
int tsp(int mask,int pos)
{
    if(mask==((1<<n)-1))
    return dist[pos][0];

    if(dp[mask][pos]!=-1)
    return dp[mask][pos];
    int ans = INT_MAX;
    for(int city=0;city<n;city++)
    {
        if((mask & 1<<city)==0)
        {
         int newAns = dist[pos][city] + tsp((mask | 1<<city ),city);
         ans = min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main() {
    memset(dp,-1,sizeof(dp));
    
    memset(dist,0,sizeof(dist));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
           cin>>dist[i][j];
    }
    cout<<tsp(1,0);
}
