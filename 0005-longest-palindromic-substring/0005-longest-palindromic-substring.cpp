class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        int bestStart = 0, bestLen = 1;

        for (int i = 0; i < n; i++) {
            // 1) Odd length palindrome (center at i)
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = l;
                }
                l--;
                r++;
            }

            // 2) Even length palindrome (center between i and i+1)
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};
