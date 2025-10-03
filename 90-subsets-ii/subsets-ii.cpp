class Solution {
public:
    void gen(int i, vector<int>& nums, vector<int> temp,
             vector<vector<int>>& ans) {
        // int n=ums.size();
        // if (i == nums.size()) {
            ans.push_back(temp);
        //     return;
        // }

        for (int idx = i; idx < nums.size(); idx++) {
            if (i != idx && nums[idx]==nums[idx - 1])
                continue;
            temp.push_back(nums[idx]);
            gen(idx + 1, nums, temp, ans);
            temp.pop_back();
        }

        // gen(i + 1, nums, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        gen(0, nums, temp, ans);
        return ans;
    }
};