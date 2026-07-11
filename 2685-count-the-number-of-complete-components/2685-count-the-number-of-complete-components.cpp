class Solution {
private:
    void dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int& vertexCount, int& edgeCount) {
        visited[node] = true;
        vertexCount++;
        edgeCount += adj[node].size(); // Summing the degree of each node in the component

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        // Step 1: Build the adjacency list for the undirected graph
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        std::vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        // Step 2: Iterate through every node to find connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int edgeCount = 0;
                // Step 3: Run DFS to track vertices and edges in the current component
                dfs(i, adj, visited, vertexCount, edgeCount);
                // For a complete component, total degrees tracked must equal V * (V - 1)
                if (edgeCount == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        return completeComponentsCount;
    }
};