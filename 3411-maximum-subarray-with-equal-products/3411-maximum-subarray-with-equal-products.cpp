class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            int l = 1;
            
            for (int j = i; j < n; ++j) {
                if (prod > 25200) break;
                
                prod *= nums[j];
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, nums[j]);
                
                if (prod == 1LL * l * g) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};