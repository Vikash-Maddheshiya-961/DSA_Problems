class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int lb_zero = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == 0){
                if(mid >= 1 && nums[mid] == nums[mid-1]){
                    hi = mid-1;
                }
                else{
                    lb_zero = mid;
                    break;
                }
            }
            else if(nums[mid] < 0) lo = mid + 1;
            else hi = mid - 1;
        }

        if(lb_zero == -1) {
            return max(n-lo,lo);
        }

        int ub_zero = -1;
        lo = 0;
        hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == 0){
                if(mid <= n-2 && nums[mid] == nums[mid+1]){
                    lo = mid+1;
                }
                else{
                    ub_zero = mid;
                    break;
                }
            }
            else if(nums[mid] < 0) lo = mid + 1;
            else hi = mid - 1;
        }
        return max(n-1-ub_zero,lb_zero);
    }
};