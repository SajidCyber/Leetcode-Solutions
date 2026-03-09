class Solution {
    public int largestAltitude(int[] gain) {
        int ans=0,sum=0;
        for(int val : gain){
            sum+=val;
            ans=Math.max(ans,sum);
        }
        return ans;
    }
}