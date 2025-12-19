class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& triangle,
    // vector<vector<int>>& dp) {
    //     int n = triangle.size();

    //     // Base case → last row:
    //     if (i == n - 1)
    //         return triangle[i][j];

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int down = solve(i + 1, j, triangle, dp);
    //     int diagonal = solve(i + 1, j + 1, triangle, dp);

    //     return dp[i][j] = triangle[i][j] + min(down, diagonal);
    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();

    //     // Create dp with -1
    //     vector<vector<int>> dp(n);
    //     for (int i = 0; i < n; i++)
    //         dp[i] = vector<int>(triangle[i].size(), -1);

    //     // Start from top (0,0)
    //     return solve(0, 0, triangle, dp);
    // }

    /////---------recursion-----------
    // int solve(int i, int j, int m,  vector<vector<int>>& triangle) {
    //     if (i == m - 1 )
    //         return triangle[m-1][j];

    //     int dn = triangle[i][j]+solve(i + 1, j, m,  triangle);
    //     int dg = triangle[i][j]+solve(i + 1, j + 1, m,  triangle);
    //     return min(dn, dg);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     return  solve(0, 0, m, triangle);
    //
    // }

    ///--------memoization------

    // int solve(int i, int j, int m, vector<vector<int>>&
    // triangle,vector<vector<int>>& dp) {
    //     if (i == m - 1)
    //         return triangle[m - 1][j];

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int dn = triangle[i][j] + solve(i + 1, j, m, triangle,dp);
    //     int dg = triangle[i][j] + solve(i + 1, j + 1, m, triangle,dp);
    //     return dp[i][j]=min(dn, dg);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {

    //     int m = triangle.size();
    //     vector<vector<int>> dp(m);
    //     for (int i = 0; i < m; i++) {
    //         dp[i] = vector<int>(i + 1, -1);
    //     }

    //     return solve(0, 0, m, triangle,dp);
    // }

    //-------tabulation------
    // int solve(int i, int j, int m, vector<vector<int>>& triangle,
    //           vector<vector<int>>& dp) {
    //     if (i == m - 1)
    //         return triangle[m - 1][j];

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     dp[0][0] = triangle[0][0];
    //     int a = 0;

    //     int left = INT_MAX;
    //     int right = INT_MAX ;
    //     for (int x = 1; x < m - 1; x++) {
    //         for (int y = 1; y < triangle[x].size() - 1; y++) {
    //             // int cur = min(left, right);
    //             dp[x+1][y]=dp[x-1][y] + dp[x][y];
    //             dp[x+1][y+1]=dp[x-1][y-1] + dp[x][y];
    //             a+=min(dp[x+1][y],dp[x+1][y]);
    //         }   
    //     }
    //     return a;
    // }


    ////////----------------tabulation--------------===
    // int minimumTotal(vector<vector<int>>& triangle) {

    //     int m = triangle.size();
    //     vector<vector<int>> dp(m);
    //     for (int i = 0; i < m; i++) {
    //         dp[i] = vector<int>(i + 1, -1);
    //     }
    //     for(int j=0;j<m;j++){
    //         dp[m-1][j]=triangle[m-1][j];
    //     }

    //     int dn=0;
    //     int dg=0;
    //     int a=0;

    //     for (int i =m-2; i>=0; i--) {
    //         for (int j=i ;j>=0; j--) {
    //             // int cur = min(left, right);
    //             dn=dp[i+1][j]+triangle[i][j];
    //             dg=dp[i+1][j+1]+triangle[i][j];
    //             dp[i][j]=min(dn,dg);
    //         }   
    //     }
    //     return dp[0][0];
    // }



    ///space optm
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = vector<int>(i + 1, -1);
        }
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }

        int dn=0;
        int dg=0;

        

        for (int i =m-2; i>=0; i--) {
            for (int j=i ;j>=0; j--) {
                // int cur = min(left, right);
                dn=dp[i+1][j]+triangle[i][j];
                dg=dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(dn,dg);
            }   
        }
        return dp[0][0];
    }
};
