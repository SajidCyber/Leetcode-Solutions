class Solution {
    public int numOfSubarrays(int[] A, int k, int thres) {
        int n=A.length;
        int cnt=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=A[i];
        }
        int avg=sum/k;
        if(avg>=thres) cnt++;
        int st=1,end=k;
        while(end<A.length){
            sum=sum-A[st-1]+A[end];
            avg=sum/k;
            if(avg>=thres) cnt++;
            st++;end++;
        }
        return cnt++;
    }
}