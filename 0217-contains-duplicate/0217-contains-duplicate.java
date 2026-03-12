class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hm= new HashSet<>();
        for(int val: nums){
            if(hm.contains(val)){
                return true;
            }
            else{
                hm.add(val);
            }
        }
        return false;
    }

}