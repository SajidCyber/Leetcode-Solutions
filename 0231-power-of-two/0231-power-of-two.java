class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n>0 && ((n&(n-1))==0)) return true;
        // int z =2;
        // for(int i =0;i<31;i++){
        //     if(Math.pow(z,i)==n) return true;
        // }
        // if((1<<i)==n) return true;  [inside for for loop]
        return false;
    }
}