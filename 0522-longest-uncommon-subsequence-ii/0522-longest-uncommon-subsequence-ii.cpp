class Solution {
private:
    bool isSubsequence(const string& s1, const string& s2) {
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == s1.length();
    }

public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        int n = strs.size();
        
        for (int i = 0; i < n; i++) {
            bool isUncommon = true;
            for (int j = 0; j < n; j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) {
                maxLen = max(maxLen, static_cast<int>(strs[i].length()));
            }
        }
        
        return maxLen;
    }
};