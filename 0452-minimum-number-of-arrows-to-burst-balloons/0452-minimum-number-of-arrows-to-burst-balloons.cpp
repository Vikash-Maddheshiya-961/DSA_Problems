class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int st = points[0][0];
        int end = points[0][1];

        int arrow = 1;
        for(int i=1;i<n;i++){
            if(points[i][0] <= end){
                st = points[i][0];
                end = min(end,points[i][1]);
            }
            else{
                st = points[i][0];
                end = points[i][1];
                arrow++;
            }
        }

        return arrow;
    }
};