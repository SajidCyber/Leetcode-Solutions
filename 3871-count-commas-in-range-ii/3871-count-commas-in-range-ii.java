class Solution {
    public long countCommas(long n) {
        long t = 0;
        long th=1000;
        while(n>=th){
            t+= (n-th+1);
            if(th>n/1000)
                break;

            th*=1000;
        }
        return t;
    }
}