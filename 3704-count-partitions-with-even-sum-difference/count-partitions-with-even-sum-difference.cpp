class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        vector<int> p(n), s(n);
        p[0] = nums[0];

        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] + nums[i];

        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            s[i] = s[i + 1] + nums[i];

        int c = 0;
        for (int i = 0; i < n - 1; i++) {
            int left = p[i];
            int right = s[i + 1];
            if ((left - right) % 2 == 0)
                c++;
        }

        return c;
    }
};
