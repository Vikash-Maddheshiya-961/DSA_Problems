class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int maxi = prices[n-1];

        for(int i=n-1;i>=0;i--){
            if(prices[i] <= maxi){
                int profit = maxi - prices[i];
                max_profit = max(profit,max_profit);
            }
            else{
                maxi = prices[i];
            }
        }

        return max_profit;
    }
};