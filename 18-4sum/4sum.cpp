class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;

                int lt = j + 1;
                int rt = n - 1;
                while (lt < rt) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[lt] + nums[rt];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[lt], nums[rt]});
                        while (lt < rt && nums[lt] == nums[lt + 1])
                            lt++;
                        while (lt < rt && nums[rt] == nums[rt - 1])
                            rt--;


                        lt++;
                        rt--;    
                    }


                    else if (sum < target)
                        lt++;
                    else
                        rt--;
                }
            }
        }
        return ans;
    }
};