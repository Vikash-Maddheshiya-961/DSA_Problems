class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> mark(m,0);
        for(int i=0;i<m;i++){
            if(mark[i] == 1) continue;
            for(int j=i+1;j<m;j++){
                if(mark[i] == 0 && mark[j] == 0 && intervals[j][1] <= intervals[i][1]){
                    mark[j] = 1;
                }else if(mark[i]== 0 && mark[j] == 0 && intervals[i][0] == intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    mark[i] = 1;
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            if(mark[i] == 0) count++;
        }
        return count;
    }
};