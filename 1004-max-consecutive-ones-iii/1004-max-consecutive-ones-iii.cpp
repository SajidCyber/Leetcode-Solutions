class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int maxlen = 0;
        int zeroCount = 0; // Directly track the number of zeros in the window
        
        for (int high = 0; high < n; high++) {
            if (nums[high] == 0) {
                zeroCount++;
            }
            
            // If zeros exceed k, shrink the window from the left
            while (zeroCount > k) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }
            
            maxlen = max(maxlen, high - low + 1);
        }
        
        return maxlen;
    }
};