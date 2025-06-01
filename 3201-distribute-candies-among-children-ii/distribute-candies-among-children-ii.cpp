class Solution {
public:
    long long combi(long long sum) {
        if (sum < 0) return 0;
        return (sum + 2) * (sum + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        return combi(n)
             - 3 * combi(n - (limit + 1))
             + 3 * combi(n - 2 * (limit + 1))
             - combi(n - 3 * (limit + 1));
    }
};
