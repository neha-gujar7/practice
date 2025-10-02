class Solution {
public:
    void gen(int i, int t, vector<int>& nums, vector<int> temp,
             vector<vector<int>>& ans) {
        // int n=ums.size();
        if (i == nums.size()) {
            if (t == 0)
                ans.push_back(temp);
            return;
        }

        if (t >= 0) {
            temp.push_back(nums[i]);
            gen(i ,t-nums[i], nums, temp, ans);

            temp.pop_back();
        }

        gen(i + 1,t, nums, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        gen(0, target, nums, temp, ans);
        return ans;
    }
};