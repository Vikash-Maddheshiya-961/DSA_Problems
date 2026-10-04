class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) visited[i][j] = 0;
                else visited[i][j] = -1;
            }
        }

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        int d_row[] = {-1,1,0,0};
        int d_col[] = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            
            for(int k=0;k<4;k++){
                int new_row = row + d_row[k];
                int new_col = col + d_col[k];

                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n){
                    if(visited[new_row][new_col] == 0){
                        q.push({new_row,new_col});
                        visited[new_row][new_col] = 1;
                    }
                }
            }
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};