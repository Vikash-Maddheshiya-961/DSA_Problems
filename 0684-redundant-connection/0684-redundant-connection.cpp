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
            if(parent[u] == u){
                return u;
            }

            return parent[u] = find(parent[u]);
        }

        bool Union(int u,int v){
            int a = find(u);
            int b = find(v);

            if(a == b) return false;

            if(rank[a] < rank[b]){
                parent[a] = b;
            }
            else if(rank[b] < rank[a]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = m + 1; 
        DisjointSet ds(n);

        vector<int> ans;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(!ds.Union(u,v)){
                ans = {u,v};
            }
        }

        return ans;
    }
};