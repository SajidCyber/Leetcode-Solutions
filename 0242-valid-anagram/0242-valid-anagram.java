class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> hm = new HashMap<>();
        if(s.length()!=t.length()) return false;

        for(int i =0; i<s.length();i++){
            char c=s.charAt(i);
            hm.put(c,hm.getOrDefault(c,0)+1);
        }

         for(int i =0; i<t.length();i++){
            char c=t.charAt(i);
            hm.put(c,hm.getOrDefault(c,0)-1);
        }
        
        for(int val:hm.values()){
            if(val!=0) return false;
        }

      return true;   

        

    }
}