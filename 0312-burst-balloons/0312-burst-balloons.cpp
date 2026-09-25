class Solution {
public:
    int res[301][301];
    int solve(vector<int>& nums,int i,int j){
        if(i > j) return 0;

        if(res[i][j] != -1) return res[i][j];
        int max_coin = INT_MIN;
        for(int k=i;k<=j;k++){

            int curr_coin = nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1) + solve(nums,k+1,j);
            max_coin = max(max_coin,curr_coin);
        }

        return res[i][j] = max_coin;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(res,-1,sizeof(res));
        return solve(nums,1,n);
    }
};