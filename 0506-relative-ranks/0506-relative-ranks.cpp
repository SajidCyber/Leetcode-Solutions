class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> sorted_scores(n);
        for (int i = 0; i < n; ++i) {
            sorted_scores[i] = {score[i], i};
        }
        
        sort(sorted_scores.rbegin(), sorted_scores.rend());
        
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            int original_idx = sorted_scores[i].second;
            if (i == 0) {
                ans[original_idx] = "Gold Medal";
            } else if (i == 1) {
                ans[original_idx] = "Silver Medal";
            } else if (i == 2) {
                ans[original_idx] = "Bronze Medal";
            } else {
                ans[original_idx] = to_string(i + 1);
            }
        }
        return ans;
    }
};