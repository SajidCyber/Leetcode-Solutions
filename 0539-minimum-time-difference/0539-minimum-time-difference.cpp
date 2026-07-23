class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;

        vector<int> minutes;
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        int min_diff = 1440 - minutes.back() + minutes.front();

        for (int i = 0; i < minutes.size() - 1; ++i) {
            min_diff = min(min_diff, minutes[i + 1] - minutes[i]);
        }

        return min_diff;
    }
};