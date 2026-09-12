class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 4>> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][1], intervals[i][0], intervals[i][2], i};
        }
        sort(sorted_intervals.begin(), sorted_intervals.end());

        vector<int> prev_non_overlap(n);
        for (int i = 0; i < n; ++i) {
            int l = 0, r = i - 1, res = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (sorted_intervals[mid][0] < sorted_intervals[i][1]) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            prev_non_overlap[i] = res;
        }

        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));

        for (int k = 1; k <= 4; ++k) {
            for (int i = 1; i <= n; ++i) {
                dp[k][i] = dp[k][i - 1];

                int p = prev_non_overlap[i - 1];
                long long current_weight = sorted_intervals[i - 1][2];
                int original_idx = sorted_intervals[i - 1][3];

                long long take_weight = current_weight + (p != -1 ? dp[k - 1][p + 1].first : 0);
                vector<int> take_indices = p != -1 ? dp[k - 1][p + 1].second : vector<int>{};
                take_indices.push_back(original_idx);
                sort(take_indices.begin(), take_indices.end());

                if (take_weight > dp[k][i].first) {
                    dp[k][i] = {take_weight, take_indices};
                } else if (take_weight == dp[k][i].first && !take_indices.empty()) {
                    if (dp[k][i].second.empty() || take_indices < dp[k][i].second) {
                        dp[k][i] = {take_weight, take_indices};
                    }
                }
            }
        }

        pair<long long, vector<int>> best = {0, {}};
        for (int k = 1; k <= 4; ++k) {
            if (dp[k][n].first > best.first) {
                best = dp[k][n];
            } else if (dp[k][n].first == best.first && !dp[k][n].second.empty()) {
                if (best.second.empty() || dp[k][n].second < best.second) {
                    best = dp[k][n];
                }
            }
        }

        return best.second;
    }
};