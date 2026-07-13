class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int prev= nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                temp.push_back(nums[i]);
                prev = nums[i];
            }
        }
        int size = temp.size();
        for(int i=0;i<size;i++){
            nums[i] = temp[i];
        }
        return size;
    }
};