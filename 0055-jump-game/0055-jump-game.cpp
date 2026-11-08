class Solution {
private:
    vector<int> res;
    int n;
    bool solve(vector<int>& nums,int idx){
        if(idx == n-1) return true;

        if(res[idx] != -1) return res[idx];

        for(int jmp=1;jmp<=nums[idx];jmp++){
            if(solve(nums,idx+jmp)) return res[idx] = 1;
        }

        return res[idx] = 0;
    }
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        res.assign(n+1,-1);
        return solve(nums,0);
    }
};