class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        auto dfs_original = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_seen = last_seen[char_idx];

            if (prev_seen != -1) {
                new_parent[u] = prev_seen;
            }

            last_seen[char_idx] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            last_seen[char_idx] = prev_seen;
        };

        dfs_original(dfs_original, 0);

        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfs_new = [&](auto& self, int u) -> void {
            for (int v : new_adj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        dfs_new(dfs_new, 0);

        return ans;
    }
}
;