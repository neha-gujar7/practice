class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double sub_sum = 1.0;  // sum of dp[t] for last maxPts with t < k
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = sub_sum / maxPts;

            if (i < k) {
                // Still can draw more from i, include it in sub_sum
                sub_sum += dp[i];
            } else {
                // i >= k → game ends at i
                ans += dp[i];
            }

            if (i - maxPts >= 0) {
                sub_sum -= dp[i - maxPts];
            }
        }

        return ans;
    }
};
