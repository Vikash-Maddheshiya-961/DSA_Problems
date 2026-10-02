class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neigh : adj[node]){
                if(visited[neigh] == 0){
                    q.push(neigh);
                    visited[neigh] = 1;
                }
            }
        }

        return visited[destination];
    }
};