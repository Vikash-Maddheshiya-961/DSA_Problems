class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int digit = 0;
        for(int i=0;i<n;i++){
            digit ^= nums[i];
        }
        return digit;
    }
};