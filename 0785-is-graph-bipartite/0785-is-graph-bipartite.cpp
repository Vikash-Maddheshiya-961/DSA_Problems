class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node,int parent){
        if(parent == -1){
            color[node] = 0;
        }
        else color[node] = !color[parent];

        for(int neigh:graph[node]){
            if(color[neigh] == -1){
                if(dfs(graph,color,neigh,node) == false) return false;
            }
            else if(color[neigh] == color[node]) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = 0;
        for(auto v:graph){
            for(auto val:v){
                n = max(n,val);
            }
        }
        n++;

        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph,color,i,-1) == false) return false;
            }
        }

        return true;
    }
};