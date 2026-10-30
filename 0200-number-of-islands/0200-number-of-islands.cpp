class DisjointSet{
    private:
        vector<int> sz;
        vector<int> parent;
    public:
        DisjointSet(int n){
            sz.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        
        int find(int u){
            if(parent[u] == u) return u;
            
            return parent[u] = find(parent[u]);
        }
        
        bool Union(int u,int v){
            int a = find(u);
            int b = find(v);
            
            if(a == b) return false;
            
            if(sz[a] < sz[b]){
                parent[a] = b;
                sz[b] += sz[a];
            }
            else{
                parent[b] = a;
                sz[a] += sz[b];
            }
            
            return true;
        }
        
        int size(int u){
            return sz[find(u)];
        }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == '0') continue;
                int node = row * m + col;

                for(int k=0;k<4;k++){
                    int new_row = row + dx[k];
                    int new_col = col + dy[k];

                    int neigh = new_row * m + new_col;

                    if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m){
                        if(grid[new_row][new_col] == '1'){
                            ds.Union(node,neigh);
                        }
                    }
                }
            }
        }

        int cnt = 0;

        for(int node=0;node<n*m;node++){
            int row = node / m;
            int col = node % m;
            if(grid[row][col] == '1' && ds.find(node) == node) cnt++;
        }

        return cnt;
    }
};