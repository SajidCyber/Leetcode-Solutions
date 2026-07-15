class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> dp(n);
        dp[0] = 1;
        
        vector<int> idx(k, 0);
        
        for (int i = 1; i < n; ++i) {
            long long next_ugly = LLONG_MAX;
            for (int j = 0; j < k; ++j) {
                next_ugly = min(next_ugly, dp[idx[j]] * primes[j]);
            }
            dp[i] = next_ugly;
            for (int j = 0; j < k; ++j) {
                if (dp[idx[j]] * primes[j] == next_ugly) {
                    idx[j]++;
                }
            }
        }
        
        return dp[n - 1];
    }
};