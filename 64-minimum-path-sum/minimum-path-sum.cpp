class Solution {
public:
    long long f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return 1e18;


        if(dp[i][j]!=-1) return dp[i][j];
        long long left = grid[i][j] + f(i, j - 1, n, m, grid,dp);
        long long up = grid[i][j]+ f(i - 1, j, n, m, grid,dp);
        return dp[i][j]=min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n - 1, m - 1, n, m, grid,dp);
    }
};