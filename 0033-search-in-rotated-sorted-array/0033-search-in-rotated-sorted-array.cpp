class Solution {
public:
    int binSearch(vector<int>& nums,int target,int lo,int hi){
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        // find the pivot (smallest element in array)
        int pivot = -1;
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(mid == 0){
                if(nums[mid] < nums[mid+1]){
                    pivot = mid;
                }
                else{
                    pivot = hi;
                }
                break;
            }
            else if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]){//pivot index -->smallest element
                pivot = mid;
                break;
            }
            else if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){// previous pivot index --> largest element
                pivot = mid+1;
                break;
            }
            else{// except these two element all follow --> nums[mid-1] < nums[mid] < nums[mid+1]
                if(nums[mid] > nums[n-1]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        int idx;
        if(nums[pivot] <= target && target <=nums[n-1]){
            idx = binSearch(nums,target,pivot,n-1);
        }
        else{
            idx = binSearch(nums,target,0,pivot-1);
        }
        return idx;
    }
};