class Solution {
    public boolean isPowerOfTwo(int n) {
        int z =2;
        for(int i =0;i<31;i++){
            if(Math.pow(z,i)==n) return true;
        }
        return false;
    }
}