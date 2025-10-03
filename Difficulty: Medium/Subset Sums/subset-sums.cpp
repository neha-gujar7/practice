class Solution {
  public:
  
 
  void gen(int i,int sum,vector<int>& nums,vector<int>& ans){
      if(i==nums.size()) {
          ans.push_back(sum);
          return;
      }
    
        gen(i + 1, sum+nums[i],nums, ans);
        gen(i + 1, sum,nums,  ans);
  }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
         gen(0,0,arr,ans);
         return ans;
    
    }
};