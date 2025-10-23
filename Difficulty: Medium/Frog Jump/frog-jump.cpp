class Solution {
  public:
    // int minCost(vector<int>& height) {
    //     return f(0,height);
    // }
    
    // int f(int i, vector<int> h){
    //     if(i==h.size()-1){
    //         return 0;
    //     }
    //      int next=0;
    //       int snext=1e9;
        
    //     next=abs(h[i]-h[i+1])+f(i+1,h);
    //     if(i+2<=h.size()-1){
    //         snext=abs(h[i]-h[i+2])+f(i+2,h);
    //     }
    //     return min(next,snext);
    // }
    
    
    //memoization-------------
    
    int minCost(vector<int>& height) {
        int n=height.size();
         vector<int> dp(n,-1);
        return f(0,height,dp);
        
    }
    
    
    
    int f(int i, vector<int>& h, vector<int>& dp){
        if(i==h.size()-1){
            return 0;
        }
        
        if(dp[i]!=-1) {
            return dp[i];
        }
       
        int next=0;
        int snext=1e9;
        
        next=abs(h[i]-h[i+1])+f(i+1,h,dp);
        if(i+2<h.size()){
            snext=abs(h[i]-h[i+2])+f(i+2,h,dp);
        }
        
        return dp[i]=min(next,snext);
    }
};