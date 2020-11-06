https://www.youtube.com/watch?v=6928FkPhGUA&t=1096s&ab_channel=TECHDOSE

Time --- O(n*k)
Space ---O(K)


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k==0 || n==0)
            return 0;
        int maxp = 0;
        if(k>n/2)
        {
            for(int i=0;i<n-1;i++)
            {
                if(prices[i+1]>prices[i])
                    maxp+=prices[i+1]-prices[i];
            }
            return maxp;
        }
        else
        {
            int dp[2*k];
            for(int i=0;i<2*k;i++)
            {
                if(i%2==0)
                    dp[i] = INT_MIN;
                else
                    dp[i]=0;
            }
            
            for(auto price : prices)
            {
                for(int j=0;j<2*k;j++)
                {
                    if(j==0)
                        dp[j]=max(dp[j],-price);
                    else if(j%2==0)
                        dp[j]=max(dp[j],dp[j-1]-price);
                    else 
                        dp[j]=max(dp[j],dp[j-1]+price);
                }
            }
            return dp[2*k-1];
        }
    }
};
