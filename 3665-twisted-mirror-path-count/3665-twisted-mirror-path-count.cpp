class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> next_right(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> next_down(m, vector<pair<int, int>>(n));

        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (c + 1 < n) {
                    if (grid[r][c + 1] == 0) {
                        next_right[r][c] = {r, c + 1};
                    } else {
                        next_right[r][c] = next_down[r][c + 1];
                    }
                } else {
                    next_right[r][c] = {-1, -1};
                }

                if (r + 1 < m) {
                    if (grid[r + 1][c] == 0) {
                        next_down[r][c] = {r + 1, c};
                    } else {
                        next_down[r][c] = next_right[r + 1][c];
                    }
                } else {
                    next_down[r][c] = {-1, -1};
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0) continue;

                auto [rr, rc] = next_right[r][c];
                if (rr != -1) {
                    dp[rr][rc] = (dp[rr][rc] + dp[r][c]) % MOD;
                }

                auto [dr, dc] = next_down[r][c];
                if (dr != -1) {
                    dp[dr][dc] = (dp[dr][dc] + dp[r][c]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};