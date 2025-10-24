class Solution {
public:
    // int climbStairs(int n) {
    //     return f(0, n);
    // }
    // int f(int i, int n) {
    //     if (i == n) {
    //         return 1;
    //     }
    //     if(i>n) return 0;
        
    //     return f(i + 1, n)+f(i + 2, n); ;
    // }



    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return f(0, n,dp);
    }
    int f(int i, int n,vector<int>& dp) {
        if (i == n) {
            return 1;
        }
        if(i>n) return 0;

        if(dp[i]!=-1){
            return dp[i];
        }

        
        return dp[i]=f(i + 1, n,dp)+f(i + 2, n,dp); ;
    }
};
