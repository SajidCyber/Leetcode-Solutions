class NumArray {
int PF[];
    public NumArray(int[] A) {
        PF=new int[A.length];
        PF[0]=A[0];
        for(int i=1;i<A.length;i++) PF[i]=PF[i-1]+A[i];
    }
    
    public int sumRange(int left, int right) {
        if(left==0) return PF[right];
        else return PF[right]-PF[left-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */