class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low =0;
        int high =0;
        unordered_map<char,int> f;
        int res = 0;
        int n = s.size();


        for(int high =0 ; high <n; high++){
            f[s[high]]++;

             int k = high - low +1;
            while(f[s[high]]>1){
                f[s[low]]--;
                if(f[s[low]]==0){f.erase(s[low]);}

              
low++;

            }
              
            int len = high - low +1;
            res = max(res, len);
        }
        return res;
    }
};