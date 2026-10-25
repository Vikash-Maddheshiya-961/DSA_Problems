class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for(int val:nums){
            ones = (ones ^ val) & ~(twos);
            twos = (twos ^ val) & ~(ones);
        }

        return ones;
    }
};