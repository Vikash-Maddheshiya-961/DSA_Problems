class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int flips = 0;
        int len;
        int max_len = INT_MIN;
        while(j<n){
            if(nums[j] == 1){
                j++;
            }else{
                if(flips < k){
                    flips++;
                    j++;
                }
                else{
                    len = j-i;
                    max_len = max(max_len,len);
                    while(nums[i]==1) i++;
                    i++;
                    flips--;
                }
            }
        }
        len = j-i;
        max_len = max(max_len,len);
        return max_len;
    }
};