class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int len;
        int min_len = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                len = j-i+1;
                min_len = min(min_len,len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(min_len == INT_MAX) return 0;
        return min_len;
    }
};