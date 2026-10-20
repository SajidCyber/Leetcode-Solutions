class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int drops = 0;
                int mn = INT_MAX;
                int mx = INT_MIN;

                for (int i = start; i < start + k; i++) {
                    int next = (i + 1 == start + k) ? start : i + 1;

                    if (nums[i] > nums[next]) drops++;

                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (drops > 1 || (start > 0 && prevMax > mn)) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};