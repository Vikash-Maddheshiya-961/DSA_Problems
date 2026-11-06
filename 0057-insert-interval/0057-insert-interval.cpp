class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int st = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0] > end){
                ans.push_back({st,end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = max(end,intervals[i][1]);
            }
        }

        ans.push_back({st,end});
        return ans;
    }
};