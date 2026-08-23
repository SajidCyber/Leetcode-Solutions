class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), s = 0, q = 0;
        for (int i = 0; i < n; i++) {
            int sign = (i < n / 2) ? 1 : -1;
            if (num[i] == '?') q += sign;
            else s += sign * (num[i] - '0');
        }
        return s * 2 != -q * 9;
    }
};