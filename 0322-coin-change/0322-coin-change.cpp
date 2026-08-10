class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int max_amount = amount + 1;
        vector<int> res(amount+1,max_amount);
        res[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i-coins[j] >= 0){
                    res[i] = min(res[i],res[i-coins[j]]+1);
                }
            }
        }
        if(res[amount] > amount) return -1;
        return res[amount];
    }
};