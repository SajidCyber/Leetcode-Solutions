class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hm=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int val=nums[i];
             int sval=target-val;
            if(hm.containsKey(sval)){
                int ans[]={i,hm.get(sval)};
                return ans;
            }
            hm.put(val,i);
        } 
        return new int[]{-1,-1};
    }
}