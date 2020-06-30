#include <bits/stdc++.h>
using namespace std;
int dp[1001][10001];
int solve(int *a,int n,int m,int sum2,int i)
{
    
    if(sum2>0 && sum2%m==0)
    return 1;
    if(i>=n)
    return 0;
    if(dp[i][sum2]!=-1)
    return dp[i][sum2];
    
    dp[i][sum2] =  solve(a,n,m,sum2+a[i],i+1) || solve(a,n,m,sum2,i+1);
    return dp[i][sum2];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0;i<n;i++){
	    cin>>a[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    if(n==0)
	    cout<<"0"<<endl;
	    else
	    cout<<solve(a,n,m,0,0)<<endl;
	}
	return 0;
}
