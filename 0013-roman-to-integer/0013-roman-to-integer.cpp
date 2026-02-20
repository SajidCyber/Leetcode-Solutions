class Solution {
public:
    int romanToInt(string s) {
        int val[256] = {0};
        val['I'] = 1;   val['V'] = 5;   val['X'] = 10;
        val['L'] = 50;  val['C'] = 100; val['D'] = 500;
        val['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int cur = val[(unsigned char)s[i]];
            int nxt = (i + 1 < (int)s.size()) ? val[(unsigned char)s[i + 1]] : 0;

            if (cur < nxt) ans -= cur;   // subtractive notation
            else ans += cur;
        }
        return ans;
    }
};