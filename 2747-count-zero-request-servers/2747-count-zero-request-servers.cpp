class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<vector<int>> indexedQueries(m, vector<int>(2));
        for (int i = 0; i < m; ++i) {
            indexedQueries[i] = {queries[i], i};
        }
        
        sort(indexedQueries.begin(), indexedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> serverCount;
        int l = 0, r = 0;
        int numLogs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int qTime = indexedQueries[i][0];
            int qIndex = indexedQueries[i][1];
            int windowStart = qTime - x;
            int windowEnd = qTime;
            
            while (r < numLogs && logs[r][1] <= windowEnd) {
                serverCount[logs[r][0]]++;
                r++;
            }
            
            while (l < numLogs && logs[l][1] < windowStart) {
                serverCount[logs[l][0]]--;
                if (serverCount[logs[l][0]] == 0) {
                    serverCount.erase(logs[l][0]);
                }
                l++;
            }
            
            ans[qIndex] = n - serverCount.size();
        }
        
        return ans;
    }
};