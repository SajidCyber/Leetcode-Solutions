class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), pos = 0;
        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) pos = i;
            if (nums[(i + 1) % n] != (nums[i] + 1) % n)
                inc = false;
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n)
                dec = false;
        }

        if (!inc && !dec) return -1;
        if (inc) return min(pos, n - pos + 2);
        return min(pos + 2, n - pos);
    }
};