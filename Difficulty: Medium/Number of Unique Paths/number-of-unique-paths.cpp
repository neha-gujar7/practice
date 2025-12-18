// User function template in C++

class Solution {
  public:
    // Function to find total number of unique paths.
    int NumberOfPath(int m, int n) {
        
        
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Base case: starting cell
        dp[0][0] = 1;

        // First column
        for (int i = 1; i < m; i++) {
            dp[i][0] = 1;
        }

        // First row
        for (int j = 1; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
        // code here
        
    }
};
