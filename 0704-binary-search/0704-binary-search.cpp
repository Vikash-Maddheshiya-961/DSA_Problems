class Solution {
public:
    int binary_search(vector<int>& nums,int lo, int hi, int target){
        if(lo > hi){
            return -1;
        }
        int mid = lo + (hi - lo)/2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target) return binary_search(nums,mid+1,hi,target);

        return binary_search(nums,lo,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binary_search(nums,0,n-1,target);
    }
};