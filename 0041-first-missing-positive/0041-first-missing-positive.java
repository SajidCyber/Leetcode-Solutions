class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i =0; i<n;i++){
            if(nums[i]<0){
                nums[i]=0;
            }
        }
        for(int i =0; i<n;i++){
            int positive = Math.abs(nums[i]);
            if(positive >= 1 && positive <=n){
                int actual = positive -1;
                if(nums[actual]==0){
                    nums[actual] = -1 * (n+1);
                }
                else if(nums[actual]>0){
                    nums[actual]*= -1;
                }
            }
        }
        for(int i =0; i<n;i++){
            if(nums[i]<0){
                continue;
            }
            return i+1;
        }
        return n+1;
    }
}