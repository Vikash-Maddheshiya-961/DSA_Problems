class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });

        int cnt = 1;
        int end_time = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0] >= end_time){
                cnt++;
                end_time = max(intervals[i][1],end_time);
            }
        }

        return n - cnt;
    }
};