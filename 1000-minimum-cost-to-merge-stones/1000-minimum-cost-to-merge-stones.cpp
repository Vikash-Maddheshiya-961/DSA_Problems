vector<int> prefix_sum;
int K;
int res[31][31];
int solve(int i,int j){
    if(j-i+1 < K){
        return 0;
    }

    if(res[i][j] != -1) return res[i][j];

    int min_cost = INT_MAX;
    for(int mid = i;mid < j;mid += K-1){
        int cost = solve(i,mid) + solve(mid+1,j);
        min_cost = min(min_cost,cost);
    }

    if((j-i)%(K-1) == 0){
        min_cost += prefix_sum[j+1] - prefix_sum[i];
    }

    return res[i][j] = min_cost;
}
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();


        if((n - 1)%(k - 1) != 0){
            return -1;
        }

        prefix_sum.resize(n+1,0);
        prefix_sum[0] = 0;
        for(int i=1;i<=n;i++){
            prefix_sum[i] = prefix_sum[i-1] + stones[i-1];
        }

        K = k;
        memset(res,-1,sizeof(res));
        return solve(0,n-1);
    }
};