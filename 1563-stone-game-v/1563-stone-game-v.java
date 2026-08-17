class Solution {
    int[][] memo;
    int[] sum;

    public int stoneGameV(int[] val) {
        int n = val.length;
        memo = new int[n][n];
        sum = new int[n + 1];
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + val[i];
        return solve(0, n - 1);
    }

    private int solve(int l, int r) {
        if (l == r) return 0;
        if (memo[l][r] > 0) return memo[l][r];

        int max = 0;
        for (int i = l; i < r; i++) {
            int leftSum = sum[i + 1] - sum[l];
            int rightSum = sum[r + 1] - sum[i + 1];

            if (leftSum < rightSum) {
                max = Math.max(max, leftSum + solve(l, i));
            } else if (leftSum > rightSum) {
                max = Math.max(max, rightSum + solve(i + 1, r));
            } else {
                max = Math.max(max, leftSum + Math.max(solve(l, i), solve(i + 1, r)));
            }
        }
        return memo[l][r] = max;
    }
}