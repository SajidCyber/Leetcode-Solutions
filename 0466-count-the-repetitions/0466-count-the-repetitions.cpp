class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> s1CountTo(len2 + 1, 0);
        vector<int> s2CountTo(len2 + 1, 0);
        unordered_map<int, int> s2IdxToS1Count;
        
        int s1Count = 0, s2Count = 0, s2Idx = 0;
        
        while (s1Count < n1) {
            s1Count++;
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[s2Idx]) {
                    s2Idx++;
                    if (s2Idx == len2) {
                        s2Count++;
                        s2Idx = 0;
                    }
                }
            }
            
            if (s2IdxToS1Count.count(s2Idx)) {
                int prevS1Count = s2IdxToS1Count[s2Idx];
                int prevS2Count = s2CountTo[prevS1Count];
                
                int cycleS1 = s1Count - prevS1Count;
                int cycleS2 = s2Count - prevS2Count;
                
                int remainingS1 = n1 - s1Count;
                int cycles = remainingS1 / cycleS1;
                
                s1Count += cycles * cycleS1;
                s2Count += cycles * cycleS2;
            } else {
                s2IdxToS1Count[s2Idx] = s1Count;
                s1CountTo[s1Count] = s1Count;
                s2CountTo[s1Count] = s2Count;
            }
        }
        
        return s2Count / n2;
    }
};