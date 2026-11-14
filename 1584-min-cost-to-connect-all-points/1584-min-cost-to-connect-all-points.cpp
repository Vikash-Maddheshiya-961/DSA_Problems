class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        vector<int> visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int total_cost = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) continue;

            total_cost += cost;
            visited[node] = 1;

            for(auto p:adj[node]){
                int neigh = p.first;
                int wt = p.second;

                if(!visited[neigh]){
                    pq.push({wt,neigh});
                }
            }
        }

        return total_cost;
    }
};