class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {

            if (c == ')') {
                StringBuilder temp = new StringBuilder();

                // Pop until '('
                while (stack.peek() != '(') {
                    temp.append(stack.pop());
                }

                // Remove '('
                stack.pop();

                // Push reversed string back
                for (char ch : temp.toString().toCharArray()) {
                    stack.push(ch);
                }
            } 
            else {
                stack.push(c);
            }
        }

        StringBuilder ans = new StringBuilder();

        while (!stack.isEmpty()) {
            ans.append(stack.pop());
        }

        return ans.reverse().toString();
    }
}