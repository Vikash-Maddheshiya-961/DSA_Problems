class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i == 0 || j == 0) return 1;
        if(grid[i][j]!=-1) return grid[i][j];
        return grid[i][j] = solve(grid,i,j-1) + solve(grid,i-1,j);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1);
    }
};