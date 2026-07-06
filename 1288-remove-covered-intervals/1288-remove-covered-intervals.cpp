class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        auto lambda = [](vector<int>& vec1,vector<int>& vec2){
            if(vec1[0] == vec2[0]){
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        int lastIntervalEndval = intervals[0][1];
        int count = 1;
        for(int i=1;i<m;i++){
            if(lastIntervalEndval >= intervals[i][1]){
                continue;
            }
            lastIntervalEndval = intervals[i][1];
            count++ ;
        }
        return count;
    }
};