class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0, right = 1;
        int n = nums.size();
        
        while (left < n && right < n) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else if (nums[right] - nums[left] > k) {
                left++;
            } else {
                count++;
                left++;
                while (left < n && nums[left] == nums[left - 1]) {
                    left++;
                }
                right = max(right + 1, left + 1);
            }
        }
        return count;
    }
};