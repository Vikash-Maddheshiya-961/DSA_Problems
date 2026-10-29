class DisjointSet{
    private:
        vector<int> parent;
        vector<int> size;

    public:
        DisjointSet(int n){
            size.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int Find(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = Find(parent[u]);
        }

        void Union(int u,int v){
            int a = Find(u);
            int b = Find(v);

            if(a == b) return;

            if(size[a] < size[b]){
                parent[a] = b;
                size[b] += size[a];
            }
            else{
                parent[b] = a;
                size[a] += size[b];
            }

            return;
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && isConnected[i][j] == 1){
                    ds.Union(i,j);
                }
            }
        }

        set<int> s;

        for(int i=0;i<n;i++){
            s.insert(ds.Find(i));
        }
        
        return s.size();
    }
};