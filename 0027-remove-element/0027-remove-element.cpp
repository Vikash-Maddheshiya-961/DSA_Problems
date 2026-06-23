class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,e=nums.size()-1;
        while(i<e){
            if(nums[i]==val && nums[e]!=val){
            swap(nums[i],nums[e]);
            i++;
            e--;
        }
        if(nums[i] == val && nums[e]==val){
            e--;
        }
        if(nums[i]!=val){
            i++;
        }
        }

        int k=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=val){
                k++;
            }
        }

        return k;
    }
};