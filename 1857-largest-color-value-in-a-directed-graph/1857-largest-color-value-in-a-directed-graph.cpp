class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int V = colors.size();
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(V,0);
        for(auto node:adj){
            for(auto neigh:node){
                indegree[neigh]++;
            }
        }

        vector<vector<int>> dp(V,vector<int>(26,0));

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        int visited_nodes = 0;
        int max_color = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited_nodes++;
            for(int i=0;i<26;i++){
                max_color = max(max_color,dp[node][i]);
            }

            for(auto neigh:adj[node]){
                for(int i=0;i<26;i++){
                    dp[neigh][i] = max(dp[neigh][i],dp[node][i]);
                }

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    dp[neigh][colors[neigh] - 'a']++;
                }
            }
        }

        if(visited_nodes != V) return -1;

        return max_color;
    }
};