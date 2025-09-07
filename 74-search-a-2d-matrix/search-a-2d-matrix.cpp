class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1; // Reset l and r for each row
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};