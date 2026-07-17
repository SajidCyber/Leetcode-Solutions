class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int writeIdx = 0;
        int n = chars.size();
        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[writeIdx++] = chars[i];
            int count = j - i;
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[writeIdx++] = c;
                }
            }
            i = j;
        }
        return writeIdx;
    }
};