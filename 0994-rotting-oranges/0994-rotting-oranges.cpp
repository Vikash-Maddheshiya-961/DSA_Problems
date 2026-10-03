class Solution {
public:
    void bfs(vector<vector<int>>& grid,int r,int c,int& count){
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> twos;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    twos.push_back({i,j});
                }
            }
        }
        queue<pair<int,int>> q;

        for(auto p:twos){
            q.push({p.first,p.second});
        }

        int d_rows[] = {-1,1,0,0};
        int d_cols[] = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();

            bool flag = false;
            for(int i=0; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int new_row = row + d_rows[k];
                    int new_col = col + d_cols[k];
                    if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n){
                        if(grid[new_row][new_col] == 1){
                            flag = true;
                            q.push({new_row,new_col});
                            grid[new_row][new_col] = 2;
                        }
                    }
                }
            }
            if(flag == true) count++;
        }

        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> Grid = grid;

        vector<pair<int,int>> twos;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    twos.push_back({i,j});
                }
            }
        }

        int count = 0;
        bfs(Grid,0,0,count);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(Grid[i][j] == 1) return -1;
            }
        }
        
        return count;
    }
};