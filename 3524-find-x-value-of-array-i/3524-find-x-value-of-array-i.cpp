class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int mod_x = x % k;
            
            next_dp[mod_x] = (next_dp[mod_x] + 1);

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_r = (r * mod_x) % k;
                    next_dp[next_r] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return ans;
    }
};