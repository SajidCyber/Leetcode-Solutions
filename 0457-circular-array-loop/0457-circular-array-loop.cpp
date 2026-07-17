class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto getNext = [&](int curr) {
            int next = (curr + nums[curr]) % n;
            return next >= 0 ? next : next + n;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            while (nums[slow] * nums[getNext(fast)] > 0 && 
                   nums[slow] * nums[getNext(getNext(fast))] > 0) {
                slow = getNext(slow);
                fast = getNext(getNext(fast));

                if (slow == fast) {
                    if (slow == getNext(slow)) break;
                    return true;
                }
            }

            slow = i;
            int val = nums[i];
            while (nums[slow] * val > 0) {
                int next = getNext(slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
    }
};