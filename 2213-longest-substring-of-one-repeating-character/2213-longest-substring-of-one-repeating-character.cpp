class Solution {
    struct Node {
        char leftChar, rightChar;
        int maxLen;
        int prefixLen;
        int suffixLen;
        int length;
    };

    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        res.maxLen = max(left.maxLen, right.maxLen);
        res.prefixLen = left.prefixLen;
        res.suffixLen = right.suffixLen;

        if (left.rightChar == right.leftChar) {
            res.maxLen = max(res.maxLen, left.suffixLen + right.prefixLen);

            if (left.prefixLen == left.length) {
                res.prefixLen = left.length + right.prefixLen;
            }
            if (right.suffixLen == right.length) {
                res.suffixLen = right.length + left.suffixLen;
            }
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].maxLen;
        }

        return ans;
    }
};