class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;

        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(row == n-1 && col == n-1) return dist;

                for(int dr=-1;dr<=1;dr++){
                    for(int dc=-1;dc<=1;dc++){
                        int new_row = row + dr;
                        int new_col = col + dc;

                        if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n){
                            if(grid[new_row][new_col] == 0 && visited[new_row][new_col] == 0){
                                if(new_row == n-1 && new_col == n-1) return dist + 1;
                                q.push({new_row,new_col});
                                visited[new_row][new_col] = 1;
                            }
                        }
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};