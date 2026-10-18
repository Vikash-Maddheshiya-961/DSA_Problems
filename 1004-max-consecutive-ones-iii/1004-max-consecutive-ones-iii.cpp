class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int count = 0;
        int max_len = 0;

        while(r < n){
            while(nums[r] == 0 && count >= k){
                if(nums[l] == 0) count--;
                l++;
            }

            max_len = max(max_len,r-l+1);
            if(nums[r] == 0) count++;
            r++;
        }

        return max_len;
    }
};