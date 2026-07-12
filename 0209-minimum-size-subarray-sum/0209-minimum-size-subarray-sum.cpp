class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high =0 ;
        int sum =0;
        int res = INT_MAX;
         while (high<nums.size()){  // M1 : .size not length
            sum += nums[high];
        
            while(sum>=target){

                int len = high - low +1;
                res = min(res,len); //M2: you have to find the minimum dont write max of

            
            sum = sum - nums[low];
            low++; // M3 : It is low ++ not low-- you are moving window forward
            }
            high++; //M4: high should be after inner while loop not out of inner loop 
         }
         
         
         return (res == INT_MAX)? 0 : res ;
    }
};