class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        long long res = 0, sum = 0;
        for (int a : arr) {
            sum += a;
            if (sum % 2) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
        }
        return res % 1000000007;
    }
};