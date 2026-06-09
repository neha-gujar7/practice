class Solution {
public:
    int maxi = 0;
    int solv(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (i >= m || j >= n)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int len = -1;
        int rgt = INT_MAX, dg = INT_MAX, dwn = INT_MAX;
        if (matrix[i][j] == '1') {

            rgt = solv(i, j + 1, matrix,dp);
            dg = solv(i + 1, j + 1, matrix,dp);
            dwn = solv(i + 1, j, matrix,dp);
            len = (1 + min(rgt, min(dg, dwn)));

            maxi = max(maxi, len);

            return dp[i][j]=len;
        }

        // if (matrix[i][j] == '0')
        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n,-1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                solv(i, j, matrix, dp);
            }
        }

        return maxi * maxi;
    }
};