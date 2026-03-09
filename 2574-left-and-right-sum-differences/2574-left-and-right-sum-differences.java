class Solution {
    public int[] leftRightDifference(int[] A) {
        int n=A.length;
        for(int i=1;i<n;i++){
            A[i]=A[i-1]+A[i];
        }
        int ans[]= new int[n];
        int ls,rs;

        for(int i=0;i<n;i++){
            if(i==0) ls=0;
            else ls=A[i-1];
            if(i==n-1) rs=0;
            else rs=A[n-1]-A[i];
            ans[i]=Math.abs(ls-rs);
        }

        return ans;
    }
}