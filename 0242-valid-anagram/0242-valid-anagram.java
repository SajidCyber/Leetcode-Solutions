class Solution {
    public boolean isAnagram(String s, String t) {
       int F[]=new int[26];
        for(char ch:s.toCharArray()){
            F[ch-'a']++;
        }
        for(char ch:t.toCharArray()){
            F[ch-'a']--;

        }
        for(int Fval:F){
            if(Fval!=0)
            return false;
        }
        return true;
    }
}