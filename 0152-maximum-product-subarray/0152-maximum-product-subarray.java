class Solution {
    public int maxProduct(int[] nums) {
        int maxending=nums[0];
        int minending=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.length;i++){
            int v0 =nums[i];
            int v1=maxending*nums[i];
            int v2=minending*nums[i];
            
           maxending=Math.max(v0,Math.max(v1,v2));
           minending=Math.min(v0,Math.min(v1,v2));
           ans=Math.max(ans, Math.max(  maxending,minending));
        }
        return ans;
    }
}