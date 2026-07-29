#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long comb(int n, int r, long long maxK) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > maxK) return maxK;
        }
        return res;
    }

    long long countPermutations(const vector<int>& cnt, long long maxK) {
        int rem = 0;
        for (int c : cnt) rem += c;
        long long ways = 1;
        for (int c = 0; c < 26; ++c) {
            if (!cnt[c]) continue;
            ways *= comb(rem, cnt[c], maxK);
            if (ways > maxK) return maxK;
            rem -= cnt[c];
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> full_cnt(26, 0), half_cnt(26, 0);
        for (char c : s) full_cnt[c - 'a']++;

        char mid = '\0';
        for (int c = 0; c < 26; ++c) {
            half_cnt[c] = full_cnt[c] / 2;
            if (full_cnt[c] % 2) mid = 'a' + c;
        }

        if (countPermutations(half_cnt, k + 1) < k) return "";

        string left = "";
        long long cur_k = k;
        for (int i = 0; i < n / 2; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (!half_cnt[c]) continue;
                half_cnt[c]--;
                long long ways = countPermutations(half_cnt, k + 1);
                if (ways >= cur_k) {
                    left += (char)('a' + c);
                    break;
                }
                cur_k -= ways;
                half_cnt[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return n % 2 ? left + mid + right : left + right;
    }
};