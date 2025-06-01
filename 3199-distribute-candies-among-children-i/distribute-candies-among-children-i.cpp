class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            int cs = n - i;
            if (cs <= 2 * limit)
                res += min(cs, limit) - max(0, cs - limit) + 1;
        }
        return res;
    }
};
