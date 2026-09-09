class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans(n);
        
        int odd = 1;
        int even = 0;

        for(int i=n-1;i>=0;i--){
            if(odd < n){
                ans[odd] = nums[i];
                odd += 2;
            }
            else{
                ans[even] = nums[i];
                even += 2;
            }
        }

        nums = ans;
        return;
    }
};