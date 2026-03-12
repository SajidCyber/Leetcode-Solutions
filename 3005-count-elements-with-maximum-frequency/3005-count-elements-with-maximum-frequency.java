class Solution {
    public int maxFrequencyElements(int[] A) {
        HashMap<Integer,Integer> hm=new HashMap<>();
        int max=0,sum=0;
        for(int key : A){
        hm.put(key,hm.getOrDefault(key,0)+1);
        max=Math.max(max,hm.get(key));

        }
        for(int val:hm.values()){
            if(val==max) sum=sum+val;
        }
        return sum;
        
    }
}