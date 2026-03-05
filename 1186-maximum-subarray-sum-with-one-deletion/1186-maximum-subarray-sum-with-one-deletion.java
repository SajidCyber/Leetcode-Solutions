class Solution {
    public int maximumSum(int[] a) {
        int n = a.length;

        long noDel = a[0];
        long oneDel = Long.MIN_VALUE / 4; // safe negative sentinel
        long res = a[0];

        for (int i = 1; i < n; i++) {
            long prevNoDel = noDel;

            noDel = Math.max(a[i], noDel + a[i]);
            oneDel = Math.max(prevNoDel, oneDel + a[i]);

            res = Math.max(res, Math.max(noDel, oneDel));
        }

        return (int) res;
    }
}