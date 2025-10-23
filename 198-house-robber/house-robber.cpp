class Solution {
public:
    // int rob(vector<int>& nums) {
    //     return f(0,nums);
    // }

    // int f(int i,vector<int> &nums){
    //     if(i>=nums.size()){
    //         return 0;
    //     }

    //     int nt=f(i+1,nums);
    //     int t=nums[i]+f(i+2,nums);

    //     return max(t,nt);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }

    int f(int i,vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int nt=f(i+1,nums,dp);
        int t=nums[i]+f(i+2,nums,dp);

        return dp[i]=max(t,nt);
    }
};