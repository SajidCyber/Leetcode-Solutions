class Solution {
    public int minSwaps(int[] A) {
        int gcnt=0;
        for(int val : A ){
            if(val==1) gcnt++;
        }

        int bcnt=0;
        for(int i=0;i<gcnt;i++){
            if(A[i]==0) bcnt++;
        }

        int ans=bcnt;
         if(bcnt==0) return 0;
         
         int st=1;
         int end=gcnt;
         int k=gcnt;
         while(st<A.length){
             if(A[st-1]==0) bcnt--;
             if(A[end%A.length]==0) bcnt++;
             ans=Math.min(ans,bcnt);
             st++;
             end++;
         }
         return ans;
    }
}