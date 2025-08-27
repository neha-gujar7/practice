class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate

            int lt = i + 1, rt = n - 1;
            while (lt < rt) {
                int sum = nums[i] + nums[lt] + nums[rt];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[lt], nums[rt]});
                    lt++;
                    rt--;
                    while (lt < rt && nums[lt] == nums[lt-1]) lt++;     // skip duplicates
                    while (lt < rt && nums[rt] == nums[rt+1]) rt--;     // skip duplicates
                }
                else if (sum < 0) {
                    lt++;
                }
                else {
                    rt--;
                }
            }
        }
        return ans;
    }
};
