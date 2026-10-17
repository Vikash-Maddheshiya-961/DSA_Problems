class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // adjacency matrix
        vector<vector<long long>> dist(n,vector<long long>(n,LONG_MAX));
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }

        for(int via = 0; via < n; via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] != LONG_MAX && dist[via][j] != LONG_MAX){
                        dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int mini = INT_MAX;
        int ans = -1;

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(mini >= count){
                mini = count;
                ans = i;
            }
        }

        return ans;
    }
};