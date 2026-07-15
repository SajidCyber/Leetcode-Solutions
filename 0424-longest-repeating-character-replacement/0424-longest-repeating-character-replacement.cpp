class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int maxCount = 0; // Tracks the highest frequency of any character in the window
        int maxLen = 0;
        unordered_map<char, int> f;
        
        for (int high = 0; high < s.size(); high++) {
            f[s[high]]++;
            // Update maxCount with the current character's count
            maxCount = max(maxCount, f[s[high]]);
            
            // If the remaining characters to replace exceed k, shrink the window
            while ((high - low + 1) - maxCount > k) {
                f[s[low]]--;
                low++;
            }
            
            maxLen = max(maxLen, high - low + 1);
        }
        
        return maxLen;
    }
};