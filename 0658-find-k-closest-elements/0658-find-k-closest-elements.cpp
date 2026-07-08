class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = -1;
        int lo = 0, hi = n-1;
        // first find the position of x
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid] == x){
                idx = mid;
                break;
            }
            else if(arr[mid] < x){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        // now find the closest element
        vector<int> ans;
        int lb,ub;
        int i;
        if(idx == -1){
            i = 0;
            lb = hi;
            ub = lo;
        }
        else{
            ans.push_back(arr[idx]);
            i=1;
            lb = idx-1;
            ub = idx+1;
        }

        while(i < k){
            if(lb < 0){
                ans.push_back(arr[ub]);
                ub++;
            }
            else if(ub >= n){
                ans.push_back(arr[lb]);
                lb--;
            }
            else{
                int left_diff = abs(arr[lb] - x);
                int right_diff = abs(arr[ub] - x);
                if(left_diff <= right_diff){
                    ans.push_back(arr[lb]);
                    lb--;
                }
                else{
                    ans.push_back(arr[ub]);
                    ub++;
                }
            }
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};