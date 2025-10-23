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

    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return f(0,nums,dp);
    // }



    // int f(int i,vector<int> &nums, vector<int> &dp){
    //     if(i>=nums.size()){
    //         return 0;
    //     }

    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }

    //     int nt=f(i+1,nums,dp);
    //     int t=nums[i]+f(i+2,nums,dp);

    //     return dp[i]=max(t,nt);
    // }




//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2);

//         // if (i >= nums.size()) {
//         //     return 0;
//         // }

//         // if (dp[i] != -1) {
//         //     return dp[i];
//         // }
//         // dp[n - 1] = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             int nt = dp[i+1];
//             int t = nums[i] + dp[i + 2];
//             dp[i] = max(t, nt);
//         }



// //---> do remenber in dp problems while implementing tabulation , dont make all dp elements as 0, dont initialize any element except dp[n-1] in some of the problems
//         return dp[0];

//         // return f(0, nums, dp);
//     }




 int rob(vector<int>& nums) {

        int n = nums.size();

        // vector<int> dp(n+2);
        int l=0,r=0;
        for (int i = n - 1; i >= 0; i--) {
            int nt = l;
            int t = nums[i] + r;
            int cur = max(t, nt);
            r=l;
            l=cur;
        }
        return l;

    }
};