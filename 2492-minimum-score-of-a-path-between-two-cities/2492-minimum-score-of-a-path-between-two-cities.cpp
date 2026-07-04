class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // first create the adjacency list

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // apply bfs to track the visted node and find minimum score

        vector<int> visited(n+1);
        queue<int> q;
        int score = INT_MAX;
        // start bfs
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            //Explore neighbors (this inherently ignores disconnected nodes)
            for(auto neighbor:adj[curr]){
                int next_node = neighbor.first;
                int edge_weight = neighbor.second;
                
                score = min(score,edge_weight);

                if(visited[next_node]==0){
                    visited[next_node] = 1;
                    q.push(next_node);
                }
            }
        }
        return score;
    }
};