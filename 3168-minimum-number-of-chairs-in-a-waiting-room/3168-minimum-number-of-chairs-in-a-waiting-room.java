class Solution {
    public int minimumChairs(String s) {
        int curr=0;
        int maxpeople=0;
        for(int i =0;i<s.length();i++){
            if(s.charAt(i)=='E') {
                curr++;
                maxpeople=Math.max(curr,maxpeople);
            }
            if(s.charAt(i)=='L') curr--;
        }
        return maxpeople;
    }
}