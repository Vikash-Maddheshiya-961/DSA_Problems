class Solution {
public:
    bool check(vector<int>& time,long long mid,int totalTrips){
        int n = time.size();
        long long tt = 0;
        for(int i=0;i<n;i++){
            tt += mid/(long long)time[i];
        }
        if(tt < totalTrips) return false;
        return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long max = time[0];
        for(int t : time){
            if(max < t) max = t;
        }
        long long lo = 1;
        long long hi = max*(long long)(totalTrips);
        long long min_time = hi;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            if(check(time,mid,totalTrips)){
                min_time = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return min_time;
    }
};