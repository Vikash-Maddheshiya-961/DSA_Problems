class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int count = 0;
        int max_len = 0;

        for(int r = 0;r < n;r++){
            if(nums[r] == 0) count++;

            if(count > k){
                if(nums[l] == 0) count--;
                l++;
            }

            if(count <= k){
                max_len = max(max_len,r-l+1);
            }
        }

        return max_len;
    }
};