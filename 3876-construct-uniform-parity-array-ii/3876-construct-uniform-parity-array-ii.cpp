class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mv = nums1[0];
        for (int x : nums1) {
            if(x < mv) mv = x;
        }

        if(mv % 2 != 0) {
            return true;
        }
        for(int x : nums1) {
            if(x % 2 != 0) return false;
        }
        return true;
    }
};