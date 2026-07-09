class Solution {
public:
    bool check(vector<int>& weights,int minw,int days){
        int d = 0;
        int n = weights.size();
        int w = minw;
        for(int i=0;i<n;i++){
            if((w - weights[i]) >= 0){
                w = w - weights[i];
            }else{
                w = minw -weights[i];
                d++;
            }
        }
        d++;
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxw = INT_MIN;
        long long sum = 0;
        for(int val:weights){
            if(maxw < val) maxw = val;
            sum += val;
        }
        int ans = -1;
        int lo = maxw;
        int hi = sum;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(weights,mid,days) == true){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};