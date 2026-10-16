class Solution {
private:
    typedef pair<int,pair<int,int>> pip;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight:flights){
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            adj[u].push_back({v,wt});
        }

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        queue<pip> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto &p:adj[node]){
                int neigh = p.first;
                int nfc = p.second;

                if(cost + nfc < dist[neigh] && stops <= k){
                    dist[neigh] = cost + nfc;
                    q.push({stops+1,{neigh,dist[neigh]}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};