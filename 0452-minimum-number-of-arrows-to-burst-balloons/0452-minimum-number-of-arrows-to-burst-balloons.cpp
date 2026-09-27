class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        int count = 1;

        int end = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] > end){
                count++;
                end = points[i][1];
            }
            else end = min(end,points[i][1]);
        }

        return count;
    }
};