class Solution {
public:
    int n;
    int res[100001][2][3];
    int solve(vector<int> &prices,int idx,int buy,int nt){ // nt -> number of transaction

        if(idx == n) return 0;

        if(res[idx][buy][nt] != -1) return res[idx][buy][nt];

        if(buy == 1 && nt != 2){
            int yes_buy = -prices[idx] + solve(prices,idx+1,0,nt+1);
            int not_buy = solve(prices,idx+1,1,nt);
            return res[idx][buy][nt] = max(yes_buy,not_buy);
        }

        if(buy == 1 && nt == 2) return 0;

        int sell = prices[idx] + solve(prices,idx,1,nt);
        int not_sell = solve(prices,idx+1,0,nt);

        return res[idx][buy][nt] = max(sell,not_sell);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(res,-1,sizeof(res));
        return solve(prices,0,1,0);
    }
};