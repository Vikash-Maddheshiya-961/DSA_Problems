class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int res[m][n];
        int flag = 0;
        for(int j=0;j<n;j++){
            if(flag == 1 || obstacleGrid[0][j] == 1){
                res[0][j] = 0;
                flag = 1;
            }else{
                res[0][j] = 1;
            }
        }
        flag = 0;
        for(int i=0;i<m;i++){
            if(flag == 1 || obstacleGrid[i][0] == 1){
                res[i][0] = 0;
                flag = 1;
            }else{
                res[i][0] = 1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1) res[i][j] = 0;
                else res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};