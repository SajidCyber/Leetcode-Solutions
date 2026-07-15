class Solution {
private:
    bool isSquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }

public:
    int numSquares(int n) {
        if (isSquare(n)) return 1;
        
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) return 4;
        
        for (int i = 1; i * i <= n; i++) {
            if (isSquare(n - i * i)) return 2;
        }
        
        return 3;
    }
};