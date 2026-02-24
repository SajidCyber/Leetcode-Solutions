class Solution {
    public boolean checkPerfectNumber(int n) {
        int sum=0;
        for(int i=1;i<=n/i;i++){
            if(n%i==0){
                if(i==n/i) sum+=i;
               else sum+= i+ n/i; 
            }
            
        }
        if(sum-n==n) return true;
        return false;
    }
    
}