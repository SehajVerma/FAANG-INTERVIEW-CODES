https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/


class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        
        int obuy = -prices[0];
        int osold = 0;
        int n = prices.size();
        for(int i=1;i<n;i++)
        {
            int nbuy = INT_MIN;
            int nsold = INT_MIN;
            
            if(osold - prices[i] > obuy)
            {
                nbuy = osold - prices[i];
            }
            else
            {
                nbuy = obuy;
            }
            
            if(prices[i] + nbuy - fee > osold)
            {
                nsold = prices[i] + nbuy - fee;
            }
            else
            {
                nsold = osold;
            }
            osold = nsold;
            obuy = nbuy;
        }
        return osold;
    }
};
