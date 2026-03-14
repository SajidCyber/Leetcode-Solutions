class Solution {
    public int kthGrammar(int A, int B) {
        if (B == 1) return 0;

        int bit = kthGrammar(A - 1, (B + 1) / 2);

        if (B % 2 == 1)
            return bit;
        else
            return 1 - bit;
    }
}