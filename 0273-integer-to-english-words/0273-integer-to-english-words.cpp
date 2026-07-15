#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    const vector<string> thousands = {
        "", "Thousand", "Million", "Billion"
    };

    void helper(int num, string& res) {
        if (num == 0) {
            return;
        } else if (num < 20) {
            res += belowTwenty[num] + " ";
        } else if (num < 100) {
            res += tens[num / 10] + " ";
            helper(num % 10, res);
        } else {
            res += belowTwenty[num / 100] + " Hundred ";
            helper(num % 100, res);
        }
    }

public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string result = "";
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                string chunk = "";
                helper(num % 1000, chunk);
                result = chunk + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }

        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        string cleanedResult = "";
        cleanedResult.reserve(result.size());
        bool inSpace = false;
        
        for (char c : result) {
            if (c == ' ') {
                if (!inSpace) {
                    cleanedResult += c;
                    inSpace = true;
                }
            } else {
                cleanedResult += c;
                inSpace = false;
            }
        }

        return cleanedResult;
    }
};