class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = -1;
        int q = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                x = nums[i];
                q = i;
                break;
            }
        }

        if (q == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > q; i--) {
            if (nums[i] > x) {
                swap(nums[i], nums[q]);
                break;
            }
        }

        reverse(nums.begin() + q + 1, nums.end());
    }
};