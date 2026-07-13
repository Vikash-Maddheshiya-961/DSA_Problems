class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo<hi){
            if(nums[hi] == val) hi--;
            else if(nums[lo] == val){
                swap(nums[lo],nums[hi]);
                lo++;
                hi--;
            }
            else{
                lo++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == val) ans++;
        }
        return n - ans;
    }
};