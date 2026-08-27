class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> f(26, 0);
        for (char c : s) f[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> c = f;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                if (--c[target[j] - 'a'] < 0) { ok = false; break; }
            }
            if (!ok) continue;

            for (int x = target[i] - 'a' + 1; x < 26; x++) {
                if (c[x] > 0) {
                    c[x]--;
                    string res = target.substr(0, i) + char('a' + x);
                    for (int k = 0; k < 26; k++) res += string(c[k], 'a' + k);
                    return res;
                }
            }
        }
        return "";
    }
};