#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        const long long base1 = 100003LL;
        const long long mod1 = 1000000007LL;
        const long long base2 = 100019LL;
        const long long mod2 = 1000000009LL;

        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            long long val = static_cast<long long>(nums[i]);
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
            pref1[i + 1] = (pref1[i] * base1 + val) % mod1;
            pref2[i + 1] = (pref2[i] * base2 + val) % mod2;
        }

        auto getHash = [&](int l, int r) -> long long {
            long long h1 = (pref1[r] - (pref1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
            long long h2 = (pref2[r] - (pref2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
            return (h1 << 32) ^ h2;
        };

        auto hasUniqueOfLength = [&](int len) -> bool {
            unordered_map<long long, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);
            for (int l = 0; l + len <= n; ++l) {
                long long h = getHash(l, l + len);
                ++freq[h];
            }
            for (const auto& kv : freq) {
                if (kv.second == 1) {
                    return true;
                }
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLength(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};