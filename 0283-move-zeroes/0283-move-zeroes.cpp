class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int lentemp = temp.size();
        int zeros = n-lentemp;
        while(zeros!=0){
            temp.push_back(0);
            zeros--;
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};