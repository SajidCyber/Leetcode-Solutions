class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int len=0;
     
        for(int val:arr){
            if(val%2==1){
                len++;
                if(len>=3) return true;
                
            }
            else{
                len=0;
            }
        }
        return false;
    }
}