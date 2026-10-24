class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto toDays = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            int total = d;
            for (int i = 0; i < m - 1; ++i) {
                total += days[i];
            }
            return total;
        };
        
        int arrA = toDays(arriveAlice);
        int levA = toDays(leaveAlice);
        int arrB = toDays(arriveBob);
        int levB = toDays(leaveBob);
        
        int start = max(arrA, arrB);
        int end = min(levA, levB);
        
        return max(0, end - start + 1);
    }
};