class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr = nums;
        int ans = 0;
        
        while (!isNonDecreasing(arr)) {
            int k = 0;
            int min_sum = arr[0] + arr[1];
            
            for (int i = 1; i < (int)arr.size() - 1; ++i) {
                int current_sum = arr[i] + arr[i + 1];
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    k = i;
                }
            }
            
            arr[k] = min_sum;
            arr.erase(arr.begin() + (k + 1));
            ++ans;
        }
        
        return ans;
    }

private:
    bool isNonDecreasing(const vector<int>& arr) {
        for (int i = 1; i < (int)arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};