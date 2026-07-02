class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        cost[0][0] = grid[0][0];
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> temp = q.front();
            int r = temp.first;
            int c = temp.second;
            q.pop();
            for(auto [dr,dc]:dir){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nextcost = cost[r][c] + grid[nr][nc];
                    if(nextcost < cost[nr][nc]){
                        cost[nr][nc] = nextcost;
                        q.push({nr,nc});
                    }
                }
            }
        }
        if(health - cost[m-1][n-1] >= 1) return true;
        return false;
    }
};