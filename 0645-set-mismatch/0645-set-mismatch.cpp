class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, missing = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0) {
                dup = val;
            } else {
                nums[val - 1] = -nums[val - 1];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        return {dup, missing};
    }
};