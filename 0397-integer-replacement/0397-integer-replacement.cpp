class Solution {
public:
    int integerReplacement(int n) {
        long long temp = n;
        int count = 0;
        while (temp > 1) {
            if (temp % 2 == 0) {
                temp /= 2;
            } else if (temp == 3) {
                temp--;
            } else if (temp % 4 == 3) {
                temp++;
            } else {
                temp--;
            }
            count++;
        }
        return count;
    }
};