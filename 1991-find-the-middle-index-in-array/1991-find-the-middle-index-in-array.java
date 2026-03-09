class Solution {
    public int findMiddleIndex(int[] nums) {
        int PF[] = new int[nums.length];
        PF[0] = nums[0];

        for(int i = 1; i < nums.length; i++) {
            PF[i] = PF[i - 1] + nums[i];
        }

        int SF[] = new int[nums.length];
        SF[nums.length - 1] = nums[nums.length - 1];

        for(int i = nums.length - 2; i >= 0; i--) {
            SF[i] = SF[i + 1] + nums[i];
        }

        int ls, rs;
        for(int i = 0; i < nums.length; i++) {
            if(i == 0) ls = 0;
            else ls = PF[i - 1];

            if(i == nums.length - 1) rs = 0;
            else rs = SF[i + 1];

            if(ls == rs) return i;
        }

        return -1;
    }
}