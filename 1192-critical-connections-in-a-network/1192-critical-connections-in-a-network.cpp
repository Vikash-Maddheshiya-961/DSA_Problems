class Solution {
private:
    int timer = 1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& visited,int tin[],int low[], vector<vector<int>>& bridges){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto neigh:adj[node]){
            if(neigh == parent) continue;
            if(!visited[neigh]){
                dfs(neigh,node,adj,visited,tin,low,bridges);
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
        vector<int> adj[n];
        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        for(int node=0; node<n; node++){
            if(!visited[node]){
                dfs(node,-1,adj,visited,tin,low,bridges);
            }
        }

        return bridges;
    }
};