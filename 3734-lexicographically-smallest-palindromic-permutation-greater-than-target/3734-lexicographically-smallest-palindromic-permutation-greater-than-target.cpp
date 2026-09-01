class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        int n = s.size(), m = n / 2;
        vector<int> f(26, 0);
        for (char c : s) f[c - 'a']++;

        int odd = -1;
        for (int i = 0; i < 26; i++) {
            if (f[i] % 2) {
                if (odd != -1) return ""; // More than 1 odd char count means no valid palindrome
                odd = i;
            }
            f[i] /= 2; // Keep half counts for building the left side
        }

        // Helper to construct a full palindrome given the left half of length m
        auto buildPalindrome = [&](const string& half) {
            string res = half;
            if (n % 2) res += char('a' + odd);
            string right = half;
            reverse(right.begin(), right.end());
            return res + right;
        };

        string best = "";

        // Iterate through all possible prefix lengths of the left half matching t
        for (int i = m; i >= 0; i--) {
            vector<int> cnt = f;
            bool possible = true;
            for (int j = 0; j < i; j++) {
                if (--cnt[t[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

            int start = (i == m) ? 0 : (t[i] - 'a' + 1);

            for (int x = start; x < 26; x++) {
                if (i < m && cnt[x] <= 0) continue;

                vector<int> cur_cnt = cnt;
                string half = t.substr(0, i);
                if (i < m) {
                    half += char('a' + x);
                    cur_cnt[x]--;
                }

                // Fill remaining left-half slots lexicographically
                for (int c = 0; c < 26; c++) {
                    half += string(cur_cnt[c], 'a' + c);
                }

                string cand = buildPalindrome(half);
                if (cand > t) {
                    if (best.empty() || cand < best) {
                        best = cand;
                    }
                }
            }
        }

        return best;
    }
};