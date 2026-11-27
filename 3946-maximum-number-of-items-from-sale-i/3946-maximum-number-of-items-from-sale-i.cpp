class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 0;
        for (const auto& it : items) {
            max_factor = max(max_factor, it[0]);
        }

        vector<int> bonus(n, 0);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            for (int m = f; m <= max_factor; m += f) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && items[j][0] == m) {
                        bonus[i]++;
                    }
                }
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            if (price > budget) continue;

            vector<int> next_dp = dp;

            for (int b = price; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], dp[b - price] + 1 + bonus[i]);
            }

            for (int b = price; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], next_dp[b - price] + 1);
            }

            dp = move(next_dp);
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};