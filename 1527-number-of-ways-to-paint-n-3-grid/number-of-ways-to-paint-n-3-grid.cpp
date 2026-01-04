class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    // valid row states
    string st[12] = {"RYG","RGY","RYR","RGR","YRG","YGR",
                     "YGY","YRY","GRY","GYR","GRG","GYG"};

    int solve(int r, int p) {
        if (r == 0) return 1;
        if (dp[r][p] != -1) return dp[r][p];

        int res = 0;
        string prevRow = st[p];

        for (int c = 0; c < 12; c++) {
            if (c == p) continue;

            bool bad = false;
            for (int j = 0; j < 3; j++) {
                if (st[c][j] == prevRow[j]) {
                    bad = true;
                    break;
                }
            }

            if (!bad) {
                res = (res + solve(r - 1, c)) % MOD;
            }
        }

        return dp[r][p] = res;
    }

    int numOfWays(int n) {
        dp.assign(n, vector<int>(12, -1));
        int ans = 0;

        for (int i = 0; i < 12; i++) {
            ans = (ans + solve(n - 1, i)) % MOD;
        }

        return ans;
    }
};
