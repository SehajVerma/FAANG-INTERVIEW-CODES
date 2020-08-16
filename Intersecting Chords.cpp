long long solve(long long n,long long *dp)
{
    if(dp[n]!=0)
    return dp[n];
    
    long long count=0;
    for(long long i=0;i<n;i=i+2)
    {
        count+=((solve(i,dp)%1000000007)*(solve(n-i-2,dp)%1000000007))%1000000007;
    }
    dp[n]=count;
    return dp[n]%1000000007;
}
int Solution::chordCnt(int A) {
    long long dp[2*A+1]={0};
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    return solve(2*A,dp);
}
