class Solution {
  public:
    bool gen(int i, int t, vector<int>& nums) {
        // int n=ums.size();
        if (i == nums.size()) {
            return t==0;
        }
        
        
        if(gen(i + 1,t, nums)) return true;
        if ( nums[i]<=t) {
            // temp.push_back(nums[i]);
            if(gen(i+1 ,t-nums[i], nums)) return true;
            // temp.pop_back();
        }
        return false;
        
        
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // vector<vector<int>> ans;
        // vector<int> temp;
        
        // if(ans.size()>=1) return true;
        return gen(0, k, arr);
    }
};