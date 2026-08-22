class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1, t = n;
        for (; t; t /= 10) {
            int d = t % 10;
            s += d;
            p *= d;
        }
        return n % (s + p) == 0;
    }
};