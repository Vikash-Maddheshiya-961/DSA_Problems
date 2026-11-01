class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DisjointSet(int n){
            rank.assign(n,0);
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

            if(rank[a] < rank[b]){
                parent[a] = b;
            }
            else if(rank[b]  < rank[a]){
                parent[b] = a;
            }
            else{
                parent[b] = a;
                rank[a]++;
            }

            return true;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int freeEdges = 0;
        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];

            if(!ds.Union(u,v)){
                freeEdges++;
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.find(i) == i){
                cnt++;
            }
        }

        if(freeEdges >= cnt - 1) return cnt - 1;

        return -1;
    }
};