class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(const string& s, int index, int segments, string currentIP, vector<string>& result) {
        if (segments == 4) {
            if (index == s.length()) {
                result.push_back(currentIP.substr(0, currentIP.length() - 1));
            }
            return;
        }

        int remainingLength = s.length() - index;
        int remainingSegments = 4 - segments;
        if (remainingLength < remainingSegments || remainingLength > remainingSegments * 3) {
            return;
        }

        for (int len = 1; len <= 3 && index + len <= s.length(); ++len) {
            string segmentStr = s.substr(index, len);
            int segmentValue = stoi(segmentStr);

            if (segmentValue > 255 || (len > 1 && segmentStr[0] == '0')) {
                break;
            }

            backtrack(s, index + len, segments + 1, currentIP + segmentStr + ".", result);
        }
    }
};