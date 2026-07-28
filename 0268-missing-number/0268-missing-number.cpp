class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> visit(n+1,0);
        for(int val:nums){
            visit[val] = 1;
        }
        for(int i=0;i<=n;i++){
            if(visit[i]!=1) return i;
        }
        return -1;
    }
};