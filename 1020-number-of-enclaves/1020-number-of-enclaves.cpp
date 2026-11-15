class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && (grid[i][j] == 1)){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int new_row = row + dx[k];
                int new_col = col + dy[k];

                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1 &&
                visited[new_row][new_col] == 0){
                    visited[new_row][new_col] = 1;
                    q.push({new_row,new_col});
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0) cnt++;
            }
        }

        return cnt;  
    }
};