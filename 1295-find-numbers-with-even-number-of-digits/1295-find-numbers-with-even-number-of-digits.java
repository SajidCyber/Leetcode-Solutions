class Solution {
    public int findNumbers(int[] nums) {
        int c=0;
        for(int val:nums){
            int nod=count(val);
            if(nod%2==0) c++;
        }
    return c;
       
    }
    int count(int n){
        int cd=0;
        int div=1;
        while(div<=n){
            cd++;
            div=div*10;
        }
        return cd;
    }
}