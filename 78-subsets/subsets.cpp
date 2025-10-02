class Solution {
public:
void gen(int i,vector<int>& nums, vector<int> temp, vector<vector<int>>& ans){
    // int n=ums.size();
    if(i==nums.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[i]);
    gen(i+1,nums,temp,ans);
    temp.pop_back();
     gen(i+1,nums,temp,ans);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        gen(0, nums, temp, ans);
        return ans;
    }
};