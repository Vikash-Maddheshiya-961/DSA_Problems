class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(prefix[j] <= queries[i]){
                    ans[i] = j + 1;
                    break;
                }
            }
        }
        return ans;
    }
};