class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }

        vector<string> result;
        backtrack(s, 0, l, r, result);
        return result;
    }

private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    void backtrack(const string& s, int start, int l, int r, vector<string>& result) {
        if (l == 0 && r == 0) {
            if (isValid(s)) result.push_back(s);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (i > start && s[i] == s[i - 1]) continue;

            if (r > 0 && s[i] == ')') {
                backtrack(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, result);
            } else if (l > 0 && s[i] == '(') {
                backtrack(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, result);
            }
        }
    }
};