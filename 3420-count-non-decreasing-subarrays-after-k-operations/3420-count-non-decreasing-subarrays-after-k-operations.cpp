
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int right = n - 1;

        for (int left = n - 1; left >= 0; left--) {

            int x = nums[left];
            int cnt = 1;

            // Merge smaller prefix maximum blocks
            while (!dq.empty() && dq.front().first <= x) {

                int val = dq.front().first;
                int len = dq.front().second;

                cost += 1LL * (x - val) * len;

                cnt += len;
                dq.pop_front();
            }

            dq.push_front({x, cnt});

            // Shrink window while operations exceed k
            while (cost > k) {

                int val = dq.back().first;

                cost -= 1LL * (val - nums[right]);

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                right--;
            }

            // Count valid subarrays starting at left
            ans += right - left + 1;
        }

        return ans;
    }
};
