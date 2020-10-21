https://www.interviewbit.com/problems/minimum-difference-subsets/



int Solution::solve(vector<int> &A) {
    int sum = 0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
    }
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
     dp[i][0]=1;
    for(int i=1;i<=sum;i++)
     dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
           if(A[i-1]>j)
           dp[i][j] = dp[i-1][j];
           else
           dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
        }
    }
    int diff=INT_MAX;
    for(int j=0;j<=sum/2;j++)
    {
      if(dp[n][j])
        diff = min(diff,abs(sum-2*j));
    }
    
    return diff;
}
