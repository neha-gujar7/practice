class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 1), r(n, 1);

        for (int i = 1; i < n; i++) 
            if (nums[i] > nums[i - 1])
                l[i] = l[i - 1] + 1;

        for (int i = n - 2; i >= 0; i--) 
            if (nums[i] < nums[i + 1])
                r[i] = r[i + 1] + 1;

        int res = 0;
        for (int i = 0; i < n - 1; i++) 
            res = max(res, min(l[i], r[i + 1]));

        return res;
    }
};