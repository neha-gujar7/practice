class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x1= 0, x2 = 0;
        for (int i = 0; i <= n-1; i++) {
            x1 ^= (i + 1);
            x2 ^= nums[i];
        }
        return x1 ^ x2;
    }
};
