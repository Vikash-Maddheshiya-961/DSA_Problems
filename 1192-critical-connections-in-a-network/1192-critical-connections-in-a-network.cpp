class Solution {
private:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> tin;
    vector<int> low;
    vector<vector<int>> bridges;
    int timer = 1;
    void dfs(int node,int parent){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto neigh:adj[node]){
            if(neigh == parent) continue;
            if(!visited[neigh]){
                dfs(neigh,node);
                low[node] = min(low[node],low[neigh]);
                if(tin[node] < low[neigh]){
                    bridges.push_back({node,neigh});
                }
            }
            else{
                low[node] = min(low[node],low[neigh]);
            }
        }

        return;
     }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n,0);
        tin.resize(n);
        low.resize(n);

        for(int node=0; node<n; node++){
            if(!visited[node]){
                dfs(node,-1);
            }
        }

        return bridges;
    }
};