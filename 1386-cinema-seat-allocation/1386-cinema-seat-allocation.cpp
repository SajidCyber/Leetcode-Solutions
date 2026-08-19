class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << (col - 2));
            }
        }
        
        int total = (n - reserved.size()) * 2;
        
        for (auto& [row, mask] : reserved) {
            bool left = (mask & 0b00001111) == 0;
            bool right = (mask & 0b11110000) == 0;
            bool mid = (mask & 0b00111100) == 0;
            
            if (left && right) {
                total += 2;
            } else if (left || right || mid) {
                total += 1;
            }
        }
        
        return total;
    }
};