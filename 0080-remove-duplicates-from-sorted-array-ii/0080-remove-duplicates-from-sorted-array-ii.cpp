class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int prev = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                temp.push_back(nums[i]);
                prev = nums[i];
                count = 1;
            }
            else{
                if(count!=0){
                    temp.push_back(nums[i]);
                    count--;
                }
            }
        }
        nums = temp;
        return nums.size();
    }
};