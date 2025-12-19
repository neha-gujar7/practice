class Solution {
public:
    //-----recursive---------
    // int solve(int i, int j, vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     // int m=matrix[0].size();

    //     if (i == n - 1)
    //         return matrix[n - 1][j];
    //     int ld = INT_MAX, d = INT_MAX, rd = INT_MAX;

    //         if (j > 0) {
    //             ld = solve(i + 1, j - 1, matrix);
    //         }
    //         d = solve(i + 1, j, matrix);
    //         if (j < n - 1) {
    //             rd = solve(i + 1, j + 1, matrix);
    //         }

    //     return matrix[i][j] + min(ld, min(d, rd));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int res=INT_MAX;
    //     for(int i=0;i<matrix.size();i++){
    //         res=min(res,solve(0, i, matrix));
    //     }
    //     return res;

    // }

    /// TLE-- SO MEMOIZATION
    // int solve(int i, int j, vector<vector<int>>& matrix,
    //           vector<vector<int>>& dp) {
    //     int n = matrix.size();

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (i == n - 1){
    //         return  dp[i][j] = matrix[i][j];;

    //     }

    //     int ld = INT_MAX, d = INT_MAX, rd = INT_MAX;

    //     if (j > 0) {
    //         ld = solve(i + 1, j - 1, matrix, dp);
    //     }
    //     d = solve(i + 1, j, matrix, dp);
    //     if (j < n - 1) {
    //         rd = solve(i + 1, j + 1, matrix, dp);
    //     }

    //     return dp[i][j] = matrix[i][j] + min(ld, min(d, rd));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int res = INT_MAX;
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     for (int i = 0; i < matrix.size(); i++) {
    //         res = min(res, solve(0, i, matrix, dp));
    //     }
    //     return res;
    // }

    // again TLE-> go till tabulation part

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < matrix.size(); i++) {
            dp[n-1][i] = matrix[n-1][i];
        }

    

        
        for (int i = n-2; i >=0 ; i--) {
            int ld = INT_MAX, d = INT_MAX, rd = INT_MAX;

            for (int j = n-1; j >= 0; j--) {
                if (j > 0) {
                    ld = dp[i + 1][ j - 1];
                }
                d = dp[i + 1][j];
                if (j < n - 1) {
                    rd = dp[i + 1][ j + 1];
                }
                dp[i][j] = matrix[i][j] + min(ld, min(d, rd));

            }
        }

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }

        return ans;
        // return res;
    }

    ////always take care while tabulatind, the variables snext lr next need to be updated inside the loop only
};