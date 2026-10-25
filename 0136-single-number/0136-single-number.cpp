class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = 0;

        for(int val:nums){
            unique = unique ^ val;
        }

        return unique;
    }
};