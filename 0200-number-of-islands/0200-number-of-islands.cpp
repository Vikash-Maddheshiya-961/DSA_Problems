class Solution {
public:
    void dfs(vector<vector<int>>& visited,int r, int c,int& m, int& n){
        visited[r][c] = 1;

        int d_rows[] = {-1,1,0,0};
        int d_cols[] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int i = d_rows[k];
            int j = d_cols[k];
            if(r+i >= 0 && r+i < m && c+j >= 0 && c+j < n){
                if(visited[r+i][c+j] == 0){
                    dfs(visited,r+i,c+j,m,n);
                }
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    visited[i][j] = 0;
                }
                else{
                    visited[i][j] = -1;
                }
            }
        }

        int count = 0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(visited[r][c] == 0){
                    dfs(visited,r,c,m,n);
                    count++;
                }
            }
        }

        return count;
    }
};