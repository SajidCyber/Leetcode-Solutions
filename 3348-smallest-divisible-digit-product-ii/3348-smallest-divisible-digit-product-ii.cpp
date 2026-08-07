#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int p : {2, 3, 5, 7}) {
            while (temp % p == 0) {
                temp /= p;
            }
        }
        if (temp > 1) return "-1";

        auto get_factors = [](long long val) -> vector<int> {
            int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
            while (val % 2 == 0) { c2++; val /= 2; }
            while (val % 3 == 0) { c3++; val /= 3; }
            while (val % 5 == 0) { c5++; val /= 5; }
            while (val % 7 == 0) { c7++; val /= 7; }
            return {c2, c3, c5, c7};
        };

        vector<int> req = get_factors(t);
        int req2 = req[0], req3 = req[1], req5 = req[2], req7 = req[3];

        auto get_min_digits = [](int r2, int r3, int r5, int r7) -> string {
            int d9 = r3 / 2; r3 %= 2;
            int d8 = r2 / 3; r2 %= 3;
            int d6 = 0;
            if (r2 > 0 && r3 > 0) {
                d6 = 1;
                r2--;
                r3--;
            }
            int d4 = r2 / 2; r2 %= 2;
            int d2 = r2;
            int d3 = r3;
            int d5 = r5;
            int d7 = r7;

            string res = "";
            res.append(d2, '2');
            res.append(d3, '3');
            res.append(d4, '4');
            res.append(d5, '5');
            res.append(d6, '6');
            res.append(d7, '7');
            res.append(d8, '8');
            res.append(d9, '9');
            sort(res.begin(), res.end());
            return res;
        };

        int n = num.length();
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);

        auto get_digit_factors = [](int d) -> vector<int> {
            if (d == 1) return {0, 0, 0, 0};
            if (d == 2) return {1, 0, 0, 0};
            if (d == 3) return {0, 1, 0, 0};
            if (d == 4) return {2, 0, 0, 0};
            if (d == 5) return {0, 0, 1, 0};
            if (d == 6) return {1, 1, 0, 0};
            if (d == 7) return {0, 0, 0, 1};
            if (d == 8) return {3, 0, 0, 0};
            if (d == 9) return {0, 2, 0, 0};
            return {0, 0, 0, 0};
        };

        bool has_zero = false;
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (d == 0) {
                has_zero = true;
                first_zero = i;
                break;
            }
            vector<int> f = get_digit_factors(d);
            pref2[i + 1] = pref2[i] + f[0];
            pref3[i + 1] = pref3[i] + f[1];
            pref5[i + 1] = pref5[i] + f[2];
            pref7[i + 1] = pref7[i] + f[3];
        }

        if (!has_zero) {
            if (pref2[n] >= req2 && pref3[n] >= req3 && pref5[n] >= req5 && pref7[n] >= req7) {
                return num;
            }
        }

        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            int cur_d = num[i] - '0';
            int cur2 = pref2[i], cur3 = pref3[i], cur5 = pref5[i], cur7 = pref7[i];

            for (int next_d = cur_d + 1; next_d <= 9; next_d++) {
                vector<int> f = get_digit_factors(next_d);
                int rem2 = max(0, req2 - (cur2 + f[0]));
                int rem3 = max(0, req3 - (cur3 + f[1]));
                int rem5 = max(0, req5 - (cur5 + f[2]));
                int rem7 = max(0, req7 - (cur7 + f[3]));

                string req_digits = get_min_digits(rem2, rem3, rem5, rem7);
                int rem_len = n - 1 - i;

                if ((int)req_digits.length() <= rem_len) {
                    string res = num.substr(0, i);
                    res += to_string(next_d);
                    res.append(rem_len - req_digits.length(), '1');
                    res += req_digits;
                    return res;
                }
            }
        }

        string req_digits = get_min_digits(req2, req3, req5, req7);
        int target_len = max(n + 1, (int)req_digits.length());
        string res = string(target_len - req_digits.length(), '1') + req_digits;
        return res;
    }
};