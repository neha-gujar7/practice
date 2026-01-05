class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        int cn = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    cn++;
                }
                int x = abs(matrix[i][j]);
                mini = min(mini, x);
                sum += abs(matrix[i][j]);
            }
        }

        if (cn % 2 == 0) {
            return sum;
        } else {
            sum = sum - 2 * mini;
        }
        return sum;
    }
};