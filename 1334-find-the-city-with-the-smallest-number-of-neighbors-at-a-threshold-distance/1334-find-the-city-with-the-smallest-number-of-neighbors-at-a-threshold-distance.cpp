class Solution {
private:
    typedef pair<int,int> pi;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pi>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int mini = INT_MAX;
        int ans = -1;
        for(int src=0; src<n; src++){
            priority_queue<pi,vector<pi>,greater<pi>> pq;
            vector<int> dist(n,INT_MAX);
            dist[src] = 0;

            pq.push({0,src});

            while(!pq.empty()){
                int dn = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if(dn > dist[node]) continue;

                for(auto p:adj[node]){
                    int neigh = p.first;
                    int wt = p.second;

                    if(dn + wt < dist[neigh]){
                        dist[neigh] = dn + wt;
                        pq.push({dn + wt,neigh});
                    }
                }
            }

            int count  = 0;
            for(int i=0;i<n;i++){
                if(dist[i] != INT_MAX && dist[i] <= distanceThreshold){
                    count++;
                }
            }

            if(mini >= count){
                mini = count;
                ans = src;
            }
        }

        return ans;
    }
};