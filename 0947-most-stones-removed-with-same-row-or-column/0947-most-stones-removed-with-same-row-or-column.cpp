class DisjointSet{
    private:
        vector<int> parent;
        vector<int> sz;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;

        for(auto v:stones){
            int row = v[0];
            int col = v[1];

            maxrow = max(maxrow,row);
            maxcol = max(maxcol,col);
        }

        DisjointSet ds(maxrow + maxcol + 2);

        unordered_set<int> uniquenode;
        for(auto v:stones){
            int rownode = v[0];
            int colnode = v[1] + maxrow + 1;

            ds.Union(rownode,colnode);
            uniquenode.insert(rownode);
            uniquenode.insert(colnode);
        }

        int cnt = 0;
        for(auto node:uniquenode){
            if(ds.find(node) == node) cnt++;
        }

        return n - cnt;
    }
};