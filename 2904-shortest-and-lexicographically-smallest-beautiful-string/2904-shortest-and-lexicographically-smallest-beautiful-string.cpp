class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') cnt++;
                if (cnt == k) {
                    string sub = s.substr(i, j - i + 1);
                    if (ans.empty() || sub.length() < ans.length() || (sub.length() == ans.length() && sub < ans)) {
                        ans = sub;
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};