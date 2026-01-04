class Solution {
public:
    int count_divisors(int n) {

        int c = 0, s = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                c++; 
                s += i;

                if (i != n / i) {
                    c++; 
                    s += n / i;
                }
            }
        }
        return (c == 4) ? s : 0;
    }

    int sumFourDivisors(vector<int>& v) {

        int ans = 0;
        for (int x : v) {
            ans += count_divisors(x);
        }
        return ans;
    }
};
