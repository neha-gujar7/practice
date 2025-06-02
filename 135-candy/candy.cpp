class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> a(n, 1); // Left to right
        vector<int> b(n, 1); // Right to left

        // Left to right traversal
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                a[i] = a[i - 1] + 1;
            }
        }

        // Right to left traversal
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                b[i] = b[i + 1] + 1;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
        }

        return sum;
    }
};
