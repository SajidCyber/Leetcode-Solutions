import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = 0, i = 0, j = 0;
        HashSet<Character> hs = new HashSet<>();

        while (j < s.length()) {
            if (hs.contains(s.charAt(j))) {
                hs.remove(s.charAt(i));
                i++;
            } else {
                hs.add(s.charAt(j));
                len = Math.max(len, j - i + 1);
                j++;
            }
        }

        return len;
    }
}