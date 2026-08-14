class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> count;
        int left = 0, max_len = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right]]++;
            
            while (count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};