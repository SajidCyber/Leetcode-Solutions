class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build adjacency list for invocations
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // 1. BFS to find all suspicious methods starting from k
        vector<bool> suspicious(n, false);
        vector<int> q = {k};
        suspicious[k] = true;

        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push_back(v);
                }
            }
        }

        // 2. Check if any method outside suspicious set invokes a suspicious method
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        // 3. Build and return result
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!can_remove || !suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};