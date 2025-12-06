class Solution {
public:
    int mod = 1e9 + 7;

    long long solve(int idx, int n, vector<long long>& dp, vector<long long>& pre, const vector<int>& end) {
        if (idx >= n) return 1;
        if (dp[idx] != -1) return dp[idx];
        int j = end[idx];
        dp[idx] = (pre[idx + 1] - pre[j + 2] + mod) % mod;
        return dp[idx];
    }

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 2, -1);
        vector<long long> pre(n + 3, 0);
        vector<int> end(n);

        multiset<int> st;
        int r = 0;

        for (int i = 0; i < n; ++i) {
            while (r < n) {
                st.insert(nums[r]);
                int mx = *st.rbegin();
                int mn = *st.begin();
                if (mx - mn > k) {
                    st.erase(st.find(nums[r]));
                    break;
                }
                ++r;
            }
            end[i] = r - 1;
            st.erase(st.find(nums[i]));
        }

        dp[n] = 1;
        dp[n + 1] = 0;
        pre[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = solve(i, n, dp, pre, end);
            pre[i] = (dp[i] + pre[i + 1]) % mod;
        }

        return dp[0];
    }
};
