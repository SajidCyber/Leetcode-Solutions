class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len=0, ans=0;
        for(int val: nums){
            if(val==1){
                len++;
                ans=Math.max(ans,len);
            }
            else{
                len=0;
            }
        }
        return ans;
    }
}