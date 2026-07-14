class Solution {
    int memo[30][30][31];
public:
    bool isScramble(string s1, string s2) {
        memset(memo, -1, sizeof(memo));
        return helper(s1, s2, 0, 0, s1.length());
    }
private:
    bool helper(const string& s1, const string& s2, int i1, int i2, int len) {
        if (memo[i1][i2][len] != -1) return memo[i1][i2][len];
        bool match = true;
        for (int i = 0; i < len; ++i) {
            if (s1[i1 + i] != s2[i2 + i]) { match = false; break; }
        }
        if (match) return memo[i1][i2][len] = true;
        int count[26] = {0};
        for (int i = 0; i < len; ++i) {
            count[s1[i1 + i] - 'a']++;
            count[s2[i2 + i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return memo[i1][i2][len] = false;
        }
        for (int k = 1; k < len; ++k) {
            if ((helper(s1, s2, i1, i2, k) && helper(s1, s2, i1 + k, i2 + k, len - k)) ||
                (helper(s1, s2, i1, i2 + len - k, k) && helper(s1, s2, i1 + k, i2, len - k))) {
                return memo[i1][i2][len] = true;
            }
        }
        return memo[i1][i2][len] = false;
    }
};