class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        vector<pair<int, char>> vec;
        for (auto& [c, count] : freq) {
            vec.push_back({count, c});
        }
        
        sort(vec.rbegin(), vec.rend());
        
        string ans = "";
        for (auto& [count, c] : vec) {
            ans.append(count, c);
        }
        
        return ans;
    }
};