class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xor_total = 0;
        for (int num : nums) {
            xor_total ^= num;
        }
        
        unsigned int lowest_set_bit = xor_total & -xor_total;
        
        int num1 = 0;
        int num2 = 0;
        for (int num : nums) {
            if (num & lowest_set_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};
