class Solution {
public:
    int coinChange(vector<int>& coins, int A) {
        int n = coins.size();
        vector<int> t(A+1,A+1);
        t[0] = 0;
        for(int i = 1; i<=A; i++){
            for(int j=0; j<n; j++){
                if(coins[j] <= i){
                    t[i] = min(t[i],1 + t[i-coins[j]]);
                }
            }
        }
        if(t[A] > A) return -1;
        return t[A];
    }
};