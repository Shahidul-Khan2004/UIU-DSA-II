class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int best = -1;
            if (i >= x && dp[i - x] >= 0) {
                best = max(best, dp[i - x] + 1);
            }
            
            if (i >= y && dp[i - y] >= 0) {
                best = max(best, dp[i - y] + 1);
            }
            
            if (i >= z && dp[i - z] >= 0) {
                best = max(best, dp[i - z] + 1);
            }
            dp[i] = best;
        }
        if (dp[n] == -1) return 0;
        return dp[n];
    }
};