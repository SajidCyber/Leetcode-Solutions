class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        int freq[101]={0};
        bool pre[101]={false};

        for(int num:nums){
            freq[num]++;
            pre[num]=true;
        }
        
        for(int x=1; x<=100;++x){
            if(!pre[x]) 
                continue;
        
        for(int y=x+1; y<=100;++y){
            if(!pre[y]) continue;
        
        if(freq[x]!=freq[y]){
            return{x,y};
        }
        }
        }
        return{-1,-1};
    }
};