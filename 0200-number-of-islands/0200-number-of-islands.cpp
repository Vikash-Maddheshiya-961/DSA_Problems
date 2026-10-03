class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int r, int c,int& m, int& n){
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = 1;

        while(!q.empty()){
            int curr_r = q.front().first;
            int curr_c = q.front().second;
            q.pop();

            int d_rows[] = {-1,1,0,0};
            int d_cols[] = {0,0,-1,1};

            for(int k=0;k<4;k++){
                int i = d_rows[k];
                int j = d_cols[k];
                int new_r = curr_r + i;
                int new_c = curr_c + j;
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n){
                    if(visited[new_r][new_c] == 0 && grid[new_r][new_c] == '1'){
                        q.push({new_r,new_c});
                        visited[new_r][new_c] = 1;
                    }
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
                    bfs(grid,visited,r,c,m,n);
                    count++;
                }
            }
        }

        return count;
    }
};