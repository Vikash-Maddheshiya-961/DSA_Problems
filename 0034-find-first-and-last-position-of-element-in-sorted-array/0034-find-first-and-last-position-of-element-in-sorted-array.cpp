class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int lb = -1, ub = -1;
        // binary search for first occurance
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                if((mid-1) >=0 && nums[mid-1] == target){
                    hi = mid-1;
                }else{
                    lb = mid;
                    break;
                }
            }
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        // binary search for last occurance
        lo = 0;
        hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                if((mid+1) < n && nums[mid+1] == target){
                    lo = mid+1;
                }else{
                    ub = mid;
                    break;
                }
            }
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return {lb,ub};
    }
};