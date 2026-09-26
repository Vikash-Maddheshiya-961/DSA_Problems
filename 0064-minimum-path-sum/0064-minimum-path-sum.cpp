class Solution {
public:
    int res[201][201];
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 || j < 0) return INT_MAX;

        if(res[i][j] != -1) return res[i][j];
        return res[i][j] = grid[i][j] + min(solve(grid,i,j-1),solve(grid,i-1,j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(res,-1,sizeof(res));
        return solve(grid,m-1,n-1);
    }
};