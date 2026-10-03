class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> Grid = grid;

        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(Grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(Grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int d_rows[] = {-1,1,0,0};
        int d_cols[] = {0,0,-1,1};

        int minutes = 0;
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
                        if(Grid[new_row][new_col] == 1){
                            flag = true;
                            q.push({new_row,new_col});
                            Grid[new_row][new_col] = 2;
                            fresh--;
                        }
                    }
                }
            }

            if(flag == true) minutes++;
        }

        if(fresh > 0) return -1;
        
        return minutes;
    }
};