class Solution {
public:
    int help(int n,vector<int>& dp){
        
        if (n <= 1)
            return n;
        
        if(dp[n]!=-1){
            return dp[n];
        }


        return dp[n]=fib(n - 2) + fib(n - 1);
    }
    int fib(int n) {

    vector<int> dp(n+1, -1);

return help(n,dp);

    }
};