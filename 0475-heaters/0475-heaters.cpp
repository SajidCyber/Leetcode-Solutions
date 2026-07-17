class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxRadius = 0;
        int heaterIdx = 0;
        int m = heaters.size();
        for (int house : houses) {
            while (heaterIdx + 1 < m && 
                   abs(heaters[heaterIdx + 1] - house) <= abs(heaters[heaterIdx] - house)) {
                heaterIdx++;
            }
            maxRadius = max(maxRadius, abs(heaters[heaterIdx] - house));
        }
        return maxRadius;
    }
};