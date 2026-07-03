class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        // Step 1: Build adjacency list while filtering out offline intermediate nodes.
        // If an edge connects to or from an offline node, it can never be part of a valid path.
        // Node 0 and Node n-1 are always online.
        vector<vector<pair<int, int>>> adj(n);
        vector<int> allCosts;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            
            // Edges are only valid if both endpoints are online
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                allCosts.push_back(cost);
            }
        }
        
        // Sort and unique the edge costs to optimize binary search range boundaries
        sort(allCosts.begin(), allCosts.end());
        allCosts.erase(unique(allCosts.begin(), allCosts.end()), allCosts.end());
        
        // Helper function to validate if a path exists with all edge costs >= minScore
        auto isValid = [&](int minScore) -> bool {
            // dist[i] stores the minimum path accumulation cost to reach node i
            vector<long long> dist(n, -1); 
            // Min-heap tracking: {total_accumulated_cost, current_node}
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            
            dist[0] = 0;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [currentCost, u] = pq.top();
                pq.pop();
                
                if (currentCost > dist[u]) continue;
                if (u == n - 1) return currentCost <= k;
                
                for (const auto& [v, edgeCost] : adj[u]) {
                    // Ignore edges below the allowed binary search threshold score
                    if (edgeCost < minScore) continue;
                    
                    long long nextCost = currentCost + edgeCost;
                    if (dist[v] == -1 || nextCost < dist[v]) {
                        dist[v] = nextCost;
                        pq.push({nextCost, v});
                    }
                }
            }
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };
        
        // Step 2: Binary Search over unique valid edge scores
        int low = 0, high = allCosts.size() - 1;
        int answer = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(allCosts[mid])) {
                answer = allCosts[mid]; // mid score is achievable, try to find a larger one
                low = mid + 1;
            } else {
                high = mid - 1; // mid score is impossible, reduce target
            }
        }
        
        return answer;
    }
};