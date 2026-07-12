class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lb = -1;
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                if(mid >= 1 && nums[mid] == nums[mid-1]){
                    hi = mid - 1;
                }
                else{
                    lb = mid;
                    break;
                }
            }
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        if(lb == -1){
            return {};
        }

        int ub = -1;
        lo = 0;
        hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                if(mid <= n-2 && nums[mid] == nums[mid+1]){
                    lo = mid + 1;
                }
                else{
                    ub = mid;
                    break;
                }
            }
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        vector<int> ans;
        for(int i = lb; i<=ub;i++){
            ans.push_back(i);
        }
        return ans;
    }
};