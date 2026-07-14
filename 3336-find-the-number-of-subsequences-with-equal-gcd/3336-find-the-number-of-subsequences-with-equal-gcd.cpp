class Solution {
public:
    int res[201][201][201];
    int mod = 1e9+7;
    int solve (vector<int>& nums,int idx,int gcd1,int gcd2){
        if(idx == nums.size()){
            if((gcd1!=0 && gcd2!=0) && (gcd1 == gcd2)){
                return 1;
            }
            return 0;
        }

        if(res[idx][gcd1][gcd2] != -1) return res[idx][gcd1][gcd2];
        int skip = solve(nums,idx+1,gcd1,gcd2);
        int Add_in_seq1 = solve(nums,idx+1,__gcd(gcd1,nums[idx]),gcd2);
        int Add_in_seq2 = solve(nums,idx+1,gcd1,__gcd(gcd2,nums[idx]));
        
        return res[idx][gcd1][gcd2] = (0LL + skip + Add_in_seq1 + Add_in_seq2) % mod;
    }
    int subsequencePairCount(vector<int>& nums){
        memset(res, -1, sizeof(res));
        return solve(nums,0,0,0);
    }
};