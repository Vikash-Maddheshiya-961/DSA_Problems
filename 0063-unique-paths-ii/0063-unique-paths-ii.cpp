class Solution {
public:
    int res[101][101];
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || j < 0) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;

        if(res[i][j] != -1) return res[i][j];
        return res[i][j] = solve(grid,i,j-1) + solve(grid,i-1,j);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        memset(res,-1,sizeof(res));
        return solve(obstacleGrid,m-1,n-1);
    }
};