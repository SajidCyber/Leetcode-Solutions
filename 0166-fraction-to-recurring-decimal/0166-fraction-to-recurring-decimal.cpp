class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res = "";
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        res += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return res;
        
        res += ".";
        unordered_map<long long, int> mp;
        
        while (rem != 0) {
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }
            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }
        
        return res;
    }
};