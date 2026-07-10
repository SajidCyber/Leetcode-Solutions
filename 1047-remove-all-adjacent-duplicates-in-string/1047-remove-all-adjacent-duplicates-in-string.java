class Solution {
    public String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();
        
        for (char ch : s.toCharArray()) {
            int size = sb.length();
            if (size > 0 && sb.charAt(size - 1) == ch) {
                sb.deleteCharAt(size - 1);
            } else {
                sb.append(ch);
            }
        }
        
        return sb.toString();
    }
}