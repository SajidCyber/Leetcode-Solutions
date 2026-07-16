class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        
        unordered_map<char, int> charToInt = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> seen;
        unordered_set<string> repeated;
        
        int bitmask = 0;
        for (int i = 0; i < 9; ++i) {
            bitmask = (bitmask << 2) | charToInt[s[i]];
        }
        
        for (int i = 9; i < s.length(); ++i) {
            bitmask = ((bitmask << 2) & 0xFFFFF) | charToInt[s[i]];
            if (seen.count(bitmask)) {
                repeated.insert(s.substr(i - 9, 10));
            } else {
                seen.insert(bitmask);
            }
        }
        
        return vector<string>(repeated.begin(), repeated.end());
    }
};