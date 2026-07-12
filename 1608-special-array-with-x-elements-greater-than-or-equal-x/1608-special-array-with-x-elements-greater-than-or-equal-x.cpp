class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<=n;i++){
            int lo = 0;
            int hi = n-1;
            int idx = -1;
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                if(nums[mid] == i){
                    if(mid >= 1 && nums[mid] == nums[mid-1]){
                        hi = mid-1;
                    }
                    else{
                        idx = mid;
                        break;
                    }
                }
                else if(nums[mid] < i) lo = mid + 1;
                else hi = mid - 1;
            }
            if(idx != -1){
                if((n-idx) == i) return i;
            }else{
                if((n-lo) == i) return i;
            }
        }
        return -1;
    }
};