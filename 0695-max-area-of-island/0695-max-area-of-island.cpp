class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col,int& curr_area){
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;
        curr_area++;

        int d_row[] = {-1,1,0,0};
        int d_col[] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int new_row = row + d_row[k];
            int new_col = col + d_col[k];
            
            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n){
                if(grid[new_row][new_col] == 1 && visited[new_row][new_col] == 0){
                    dfs(grid,visited,new_row,new_col,curr_area);
                }
            }
        }

        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        int max_area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    int curr_area = 0;
                    dfs(grid,visited,i,j,curr_area);
                    max_area = max(max_area,curr_area);
                }
            }
        }

        return max_area;
    }
};