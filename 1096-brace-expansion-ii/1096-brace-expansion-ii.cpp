class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<set<string>> stack;
         stack.push_back({});
        vector<vector<set<string>>> ops;
        ops.push_back({});

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (c == '{') {
                stack.push_back({});
                ops.push_back({});
            } else if (c == '}') {
                set<string> cur = stack.back();
                stack.pop_back();
                vector<set<string>> groups = ops.back();
                ops.pop_back();
                
                set<string> union_set = cur;
                for (const auto& g : groups) {
                    union_set.insert(g.begin(), g.end());
                }

                if (stack.back().empty()) {
                    stack.back() = union_set;
                } else {
                    set<string> next_concat;
                    for (const string& a : stack.back()) {
                        for (const string& b : union_set) {
                            next_concat.insert(a + b);
                        }
                    }
                    stack.back() = next_concat;
                }
            } else if (c == ',') {
                ops.back().push_back(stack.back());
                stack.back().clear();
            } else {
                set<string> cur = {string(1, c)};
                if (stack.back().empty()) {
                    stack.back() = cur;
                } else {
                    set<string> next_concat;
                    for (const string& a : stack.back()) {
                        for (const string& b : cur) {
                            next_concat.insert(a + b);
                        }
                    }
                    stack.back() = next_concat;
                }
            }
        }

        set<string> res = stack.back();
        for (const auto& g : ops.back()) {
            res.insert(g.begin(), g.end());
        }

        return vector<string>(res.begin(), res.end());
    }
};