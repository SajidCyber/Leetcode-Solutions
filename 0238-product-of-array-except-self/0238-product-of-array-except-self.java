class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int prefix[]= new int[n];
        int[] suffix= new int[n];
        int[] ans=new int [n];

        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }

        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
    int lm,rm;
        for(int i=0;i<n;i++){
            if(i==0) lm=1;
            else lm=prefix[i-1];
            if(i==n-1) rm=1;
            else rm=suffix[i+1];
            ans[i]=lm*rm;
        }

        return ans;

    }
}