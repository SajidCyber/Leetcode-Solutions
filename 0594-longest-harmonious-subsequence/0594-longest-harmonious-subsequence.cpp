class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int ans = 0;
        for (auto& [num, freq] : count) {
            if (count.find(num + 1) != count.end()) {
                ans = max(ans, freq + count[num + 1]);
            }
        }
        return ans;
    }
};