class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        if(n==1) {
            return nums[0]*nums[0];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += nums[n - i - 1] * nums[n - i - 1] - nums[i] * nums[i];
        }
        if(n%2==0)return sum;
        return sum+(nums[(n)/2])*(nums[(n)/2]);
    }
};