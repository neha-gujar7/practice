class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int fp = n, fz = n, cz = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > 0) {
                fp = m;
                r = m - 1;

            } else
                l = m + 1;
        }
 l = 0;
  r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= 0) {
                fz = m;
                r = m - 1;

            } else
                l = m + 1;
        }
        int p = n - fp;
        int ng = fz;
        return max(p, ng);
    }    
};