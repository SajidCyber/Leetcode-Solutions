class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          int off=0;
        int k=1;
        int cm = 1;
        int n=nums.size();
        while(cm<n){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;
            
            }
            nums[off+1]=nums[cm];
            off++;
            k++;
            cm++;
        }
        return k;
    }
};