class Solution {

    int[][] dp;
    int[] suffix;
    int n;

    public int stoneGameII(int[] piles) {

        n = piles.length;

        dp = new int[n][n + 1];
        suffix = new int[n + 1];

        // Build suffix sum
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1);
    }

    int solve(int i, int M) {

        // All piles are taken
        if (i >= n) {
            return 0;
        }

        // Can take all remaining piles
        if (i + 2 * M >= n) {
            return suffix[i];
        }

        // Already calculated
        if (dp[i][M] != 0) {
            return dp[i][M];
        }

        int best = 0;

        for (int X = 1; X <= 2 * M; X++) {

            int newM = Math.max(M, X);

            int current =
                suffix[i] - solve(i + X, newM);

            best = Math.max(best, current);
        }

        dp[i][M] = best;

        return best;
    }
}