class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                int i = mid-1;
                while(i>=0 && nums[i] == target){
                    i--;
                }
                int lb = i+1;
                int j = mid+1;
                while(j<n && nums[j] == target){
                    j++;
                }
                int ub = j-1;
                return {lb,ub};
            }
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return {-1,-1};
    }
};