import java.util.*;

class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        HashMap<Character, Integer> hm = new HashMap<>();

        for (int i = 0; i < order.length(); i++) {
            hm.put(order.charAt(i), i);
        }

        for (int i = 0; i < words.length - 1; i++) {
            boolean res = compare(words[i], words[i + 1], hm);
            if (res == false) return false;
        }

        return true;
    }

    boolean compare(String w1, String w2, HashMap<Character, Integer> hm) {
        for (int i = 0; i < w1.length() && i < w2.length(); i++) {
            char ch1 = w1.charAt(i);
            char ch2 = w2.charAt(i);

            if (ch1 != ch2) {
                if (hm.get(ch1) < hm.get(ch2)) return true;
                else return false;
            }
        }

        if (w1.length() > w2.length()) return false;
        return true;
    }
}