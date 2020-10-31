Time --- O(N) 
Space ---O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int n = prices.size();
        if(n<2)
            return 0;
        int left[n];
        int right[n];
        left[0] = 0;
        right[n-1] = 0;
        
        int minleft = prices[0];
        int maxright = prices[n-1];
        
        for(int i=1;i<n;i++)
        {
           left[i] = max(left[i-1],prices[i]-minleft);
           minleft = min(minleft,prices[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1],maxright-prices[i]);
            maxright = max(maxright,prices[i]);
        }
        
        int maxprofit = 0;
        for(int i=0;i<n;i++)
        {
            maxprofit = max(maxprofit,left[i]+right[i]);
        }
        
        return maxprofit;
    }
};
