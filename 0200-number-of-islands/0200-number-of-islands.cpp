class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int r, int c,int& m, int& n){
        visited[r][c] = 1;

        int d_rows[] = {-1,1,0,0};
        int d_cols[] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int i = d_rows[k];
            int j = d_cols[k];
            int new_r = r+i;
            int new_c = c+j;
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n){
                if(visited[new_r][new_c] == 0 && grid[new_r][new_c] == '1'){
                    dfs(grid,visited,new_r,new_c,m,n);
                }
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        int count = 0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(visited[r][c] == 0 && grid[r][c] == '1'){
                    dfs(grid,visited,r,c,m,n);
                    count++;
                }
            }
        }

        return count;
    }
};