class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            int prev = mid-1;
            int nxt = mid+1;
            if(prev < 0){
                lo = mid+1;
                continue;
            }
            if(nxt >= n){
                hi = mid-1;
                continue;
            }
            if(arr[prev] < arr[mid] && arr[mid] > arr[nxt]){
                return mid;
            }
            else if(arr[prev] < arr[mid] && arr[mid] < arr[nxt]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return -1;
    }
};