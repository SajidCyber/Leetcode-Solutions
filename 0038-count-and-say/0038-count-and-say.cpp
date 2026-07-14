class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string next_round = "";
            int len = result.length();
            
            for (int j = 0; j < len; ++j) {
                int count = 1;
                while (j + 1 < len && result[j] == result[j + 1]) {
                    count++;
                    j++;
                }
                next_round += to_string(count) + result[j];
            }
            result = next_round;
        }
        
        return result;
    }
};