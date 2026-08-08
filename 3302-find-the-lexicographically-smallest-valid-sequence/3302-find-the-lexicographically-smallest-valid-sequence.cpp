class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> last_pos(m + 1, -1);
        last_pos[m] = n;
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            last_pos[j] = ptr;
            if (ptr >= 0) {
                ptr--;
            }
        }
        
        vector<int> ans;
        bool used_change = false;
        int i = 0;
        
        for (int j = 0; j < m; ++j) {
            while (i < n) {
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                } else {
                    if (!used_change && last_pos[j + 1] >= i + 1) {
                        used_change = true;
                        ans.push_back(i);
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            }
        }
        
        if (ans.size() < m) return {};
        return ans;
    }
};