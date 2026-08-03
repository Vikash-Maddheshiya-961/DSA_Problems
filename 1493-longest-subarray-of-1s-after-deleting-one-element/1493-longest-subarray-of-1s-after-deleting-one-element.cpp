class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int i = 0, j = 0;
        int count = 0;
        int len;
        int max_len = 0;
        while(j<n){
            if(nums[j] == 1) j++;
            else{
                if(count < k){
                    count++;
                    j++;
                }
                else{
                    len = j-i-1;
                    max_len = max(max_len,len);
                    while(nums[i]==1) i++;
                    i++;
                    count--;
                }
            }
        }
        len = j-i-1;
        max_len = max(max_len,len);
        return max_len;
    }
};