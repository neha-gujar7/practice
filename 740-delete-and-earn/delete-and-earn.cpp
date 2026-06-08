class Solution {
public:
    int solv(int i, vector<int>& v,vector<int>& dp) {
        if (i >= v.size())
            return 0;
        
        if(dp[i]!=-1) return dp[i];

        int tk = v[i] + solv(i + 2, v,dp);
        int ntk = solv(i + 1, v,dp);

        return dp[i]=max(tk, ntk);
    }



    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001, 0);
        int n=nums.size();

vector<int> dp(10001,-1);
        for (int x : nums)
            v[x] += x;

        return solv(0, v,dp);
    }
};