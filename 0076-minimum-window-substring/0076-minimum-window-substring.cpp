class Solution {
public:
    // Helper function to check if the current window satisfies 't'
    bool sahi(const vector<int>& have, const vector<int>& need) {
        for (int i = 0; i < 128; i++) {
            if (have[i] < need[i]) {
                return false; 
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int low = 0; 
        int high; 
        int res = INT_MAX; // Initialize to maximum possible value
        int start = 0;     // Tracks the beginning index of the minimum window
        int m = s.size(); 
        int n = t.size(); 

        // Vector to store character frequencies (size 128 covers all ASCII characters)
        vector<int> need(128, 0);
        vector<int> have(128, 0);

        // Populate the requirements from string t
        for (char c : t) {
            need[c]++;
        }

        for (high = 0; high < m; high++) {
            have[s[high]]++; // Add the current character to our window

            // While the current window contains all necessary characters
            while (sahi(have, need)) {
                int len = high - low + 1; // Correct length calculation
                if (res > len) {
                    res = len;
                    start = low; 
                }
                have[s[low]]--; // Shrink the window from the left
                low++;
            }
        }

        // If res was never updated, it means no valid window was found
        return (res == INT_MAX) ? "" : s.substr(start, res);
    }
};