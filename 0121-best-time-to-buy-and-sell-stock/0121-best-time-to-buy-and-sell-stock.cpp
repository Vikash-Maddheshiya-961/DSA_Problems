class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nxt_max(n,0);
        nxt_max[n-1] = INT_MIN;
        for(int i=n-2;i>=0;i--){
            nxt_max[i] = max(nxt_max[i+1],prices[i+1]);
        }
        int profit = 0;
        for(int i=0;i<=n-2;i++){
            int temp = nxt_max[i] - prices[i];
            profit = max(profit,temp);
        }
        return profit;
    }
};