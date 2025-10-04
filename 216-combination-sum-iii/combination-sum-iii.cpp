class Solution {
public:
    void gen(int i, int k,vector<int>& nums, vector<int> temp,
             vector<vector<int>>& ans, int n) {
        // int n=ums.size();
        if (k == temp.size() && n==0) {
        ans.push_back(temp);
            return;
        }

        for (int idx = i; idx < nums.size(); idx++) {
            if (i != idx && nums[idx] == nums[idx - 1])
                continue;
            temp.push_back(nums[idx]);
            gen(idx + 1, k, nums, temp, ans,n-nums[idx]);
            temp.pop_back();
        }

        // gen(i + 1, nums, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // sort(.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        gen(0,k, v, temp, ans,n);
        return ans;
    }
};