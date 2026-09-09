class Solution {
    int[] p;
    public boolean validPath(int n, int[][] e, int s, int d) {
        p = new int[n];
        for (int i = 0; i < n; i++) p[i] = i;
        for (int[] x : e) p[find(x[0])] = find(x[1]);
        return find(s) == find(d);
    }
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
}