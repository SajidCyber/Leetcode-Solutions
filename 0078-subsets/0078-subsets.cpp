class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset_num = 1 << n;
        vector<vector<int>> result;
        result.reserve(subset_num);
        for (int i = 0; i < subset_num; ++i) {
            vector<int> current;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current.push_back(nums[j]);
                }
            }
            result.push_back(current);
        }
        return result;
    }
};