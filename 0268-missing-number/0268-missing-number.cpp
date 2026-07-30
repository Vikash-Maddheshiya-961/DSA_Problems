class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Actual_Sum = n*(n+1)/2;
        int currSum = 0;
        for(int val:nums){
            currSum += val;
        }
        return Actual_Sum - currSum;
    }
};