class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> sorted_idx(n);
        iota(sorted_idx.begin(), sorted_idx.end(), 0);
        sort(sorted_idx.begin(), sorted_idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> next_hop(n);
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && nums[sorted_idx[r]] - nums[sorted_idx[l]] <= maxDiff) {
                r++;
            }
            next_hop[l] = r - 1; 
        }

        int max_log = log2(n) + 2;
        vector<vector<int>> dp(n, vector<int>(max_log));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = next_hop[i];
        }

        for (int j = 1; j < max_log; ++j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }

        vector<int> orig_to_sorted(n);
        for (int i = 0; i < n; ++i) {
            orig_to_sorted[sorted_idx[i]] = i;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = orig_to_sorted[q[0]];
            int v = orig_to_sorted[q[1]];

            if (u > v) swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (dp[u][max_log - 1] < v) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            for (int j = max_log - 1; j >= 0; --j) {
                if (dp[u][j] < v) {
                    u = dp[u][j];
                    steps += (1 << j);
                }
            }
            
            ans.push_back(steps + 1);
        }

        return ans;
    }
};