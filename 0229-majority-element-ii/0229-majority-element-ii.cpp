class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = n/3 + 1;
        vector<int> ans;

        int curr_count = 0;
        int ele = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i] != ele){
                if(curr_count >= count){
                    ans.push_back(ele);
                }
                curr_count = 1;
                ele = nums[i];
            }
            else{
                curr_count++;
            }
        }

        if(curr_count >= count){
            ans.push_back(ele);
        }
        return ans;
    }
};