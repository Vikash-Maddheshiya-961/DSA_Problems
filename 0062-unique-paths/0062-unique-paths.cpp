class Solution {
public:
    int tot_path(int row,int col, int m,int n,vector<vector<int>>& path){
        if(row == m-1) return 1;
        if(col == n-1) return 1;
        if(path[row][col] != 0) return path[row][col];
        path[row][col] = tot_path(row+1,col,m,n,path) + tot_path(row,col+1,m,n,path);
        return path[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n,0));
        return tot_path(0,0,m,n,path);
    }
};