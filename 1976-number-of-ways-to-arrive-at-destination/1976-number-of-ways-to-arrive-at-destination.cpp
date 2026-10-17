class Solution {
private:
    typedef pair<long long,long long> pi;
    long long mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pi>> adj(n);
        for(auto edge:roads){
            long long u = edge[0];
            long long v = edge[1];
            long long wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});

        vector<long long> dist(n,LONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n,0);
        ways[0] = 1;

        while(!pq.empty()){
            long long dn = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            if(dn > dist[node]) continue;

            for(auto p:adj[node]){
                long long neigh = p.first;
                long long wt = p.second;

                if(dn + wt < dist[neigh]){
                    dist[neigh] = dn + wt;
                    ways[neigh] = ways[node]%mod;
                    pq.push({dist[neigh],neigh});
                }
                else if(dn + wt == dist[neigh]){
                    ways[neigh] = (ways[neigh]%mod + ways[node]%mod)%mod;
                }
            }
        }

        return ways[n-1];
    }
};