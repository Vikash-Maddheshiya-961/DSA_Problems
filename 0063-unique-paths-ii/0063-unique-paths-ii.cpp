class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>& res){
        if(i == 0 && j == 0) return 1;
        if(res[i][j] != -1) return res[i][j];
        int leftpath = 0,toppath = 0;
        if(j-1 >= 0 && obstacleGrid[i][j-1] != 1) leftpath = solve(obstacleGrid,i,j-1,res);
        if(i-1 >=0 && obstacleGrid[i-1][j] != 1) toppath = solve(obstacleGrid,i-1,j,res);
        return res[i][j] = leftpath + toppath;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> res(m,vector<int>(n,-1));
        return solve(obstacleGrid,m-1,n-1,res);
    }
};