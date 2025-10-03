class Solution {
public:
  void gen(int i, int t, vector<int>& nums, vector<int>& temp,
             vector<vector<int>>& ans) {
        if (t == 0) { 
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue; // skip duplicates
            if (nums[j] > t) break; // pruning
            temp.push_back(nums[j]);
            gen(j + 1, t - nums[j], nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        gen(0, target, candidates, temp, ans);
        return ans;
    }
};
