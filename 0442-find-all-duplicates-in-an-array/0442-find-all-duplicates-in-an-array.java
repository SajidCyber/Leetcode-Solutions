class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        HashSet<Integer> dup= new HashSet<>();
        HashSet<Integer> seen= new HashSet<>();
        for(int x: nums){
           
            if(seen.contains(x))  dup.add(x);
            else seen.add(x);
            

        }
        return new ArrayList<>(dup);
    }
}