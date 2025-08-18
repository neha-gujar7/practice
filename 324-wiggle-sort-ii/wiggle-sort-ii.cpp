class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortd(nums);
        sort(sortd.begin(), sortd.end());
        int mid = (n + 1) / 2;
        int i = mid - 1, j = n - 1;
        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) nums[k] = sortd[i--];
            else nums[k] = sortd[j--];
        }
    }
};
