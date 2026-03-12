import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String A[] = s1.split(" ");
        String B[] = s2.split(" ");   // fixed Strinng -> String
        
        HashMap<String, Integer> hm = new HashMap<>();

        for (String word : A) {
            hm.put(word, hm.getOrDefault(word, 0) + 1);
        }

        for (String word : B) {
            hm.put(word, hm.getOrDefault(word, 0) + 1);
        }

        ArrayList<String> al = new ArrayList<>();  // fixed syntax

        for (String word : hm.keySet()) {
            if (hm.get(word) == 1) {
                al.add(word);   // fixed al.word -> al.add
            }
        }

        String ans[] = new String[al.size()];  // fixed array creation

        for (int i = 0; i < ans.length; i++) {  // fixed loop condition
            ans[i] = al.get(i);
        }

        return ans;
    }
}