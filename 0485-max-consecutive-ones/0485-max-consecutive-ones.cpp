class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int max_count = 0;
        while(i<n && j<n){
            if(nums[i] == 1 && nums[j] == 1){
                int curr_count = j-i+1;
                if(max_count < curr_count) max_count = curr_count;
                j++;
            }
            else if(nums[i] == 0 && nums[j] == 0){
                i++;
                j++;
            }
            else if(nums[i] == 0 && nums[j] == 1){
                i++;
            }
            else{
                i = j;
            }
        }
        return max_count;
    }
};