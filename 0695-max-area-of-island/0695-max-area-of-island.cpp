class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        int max_area = 0;
        int d_row[] = {-1,1,0,0};
        int d_col[] = {0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    int curr_area = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        curr_area++;
                        q.pop();

                        for(int k=0;k<4;k++){
                            int new_row = row + d_row[k];
                            int new_col = col + d_col[k];

                            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n){
                                if(grid[new_row][new_col] == 1 && visited[new_row][new_col] == 0){
                                    q.push({new_row,new_col});
                                    visited[new_row][new_col] = 1;
                                }
                            }
                        }
                    }
                    max_area = max(max_area,curr_area);
                }
            }
        }

        return max_area;
    }
};