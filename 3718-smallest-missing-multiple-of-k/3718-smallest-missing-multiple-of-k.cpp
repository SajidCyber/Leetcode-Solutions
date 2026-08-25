class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int mult = k;
        while (s.count(mult)) {
            mult += k;
        }
        return mult;
    }
};