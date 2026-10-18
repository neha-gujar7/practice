class Solution {
public:
    int getdigitsum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        auto lambda = [&](int num1, int num2) {
            int dsum1 = getdigitsum(num1);
            int dsum2 = getdigitsum(num2);
            if (dsum1 != dsum2)
                return dsum1 < dsum2;

            return num1 < num2;
        };
        sort(v.begin(), v.end(), lambda);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == v[i])
                continue;
            int idx = mp[v[i]];

            swap(nums[i], nums[idx]);

            mp[nums[idx]] = idx;
            mp[nums[i]] = i;

            cnt++;
        }

        return cnt;
    }
};