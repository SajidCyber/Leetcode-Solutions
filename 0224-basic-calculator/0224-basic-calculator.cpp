class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0;
        int sign = 1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                long long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            } else if (c == ')') {
                int prev_sign = st.top();
                st.pop();
                int prev_sum = st.top();
                st.pop();
                sum = prev_sum + prev_sign * sum;
            }
        }
        return sum;
    }
};