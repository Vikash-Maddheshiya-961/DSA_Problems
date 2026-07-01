class Solution {
private:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Validates whether a path from (0,0) to (n-1,n-1) exists with a minimum safeness factor of 'min_safeness'
    bool isValidPath(const vector<vector<int>>& dist, int min_safeness, int n) {
        if (dist[0][0] < min_safeness || dist[n - 1][n - 1] < min_safeness) {
            return false;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) {
                return true;
            }

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && dist[nr][nc] >= min_safeness) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Base case: If start or end contains a thief
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Multi-Source BFS initialization
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        // Compute shortest distance to any thief for every cell
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Binary search on the answer range
        int low = 0, high = 2 * n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidPath(dist, mid, n)) {
                ans = mid;       // 'mid' is feasible, try to maximize it
                low = mid + 1;
            } else {
                high = mid - 1;  // 'mid' is too dangerous, decrease safety requirements
            }
        }

        return ans;
    }
};
