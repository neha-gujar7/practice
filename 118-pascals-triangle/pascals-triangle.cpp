class Solution {
public:
    vector<vector<int>> generate(int nrow) {
        vector<vector<int>> tri;
        for (int i = 0; i < nrow; i++) {
            tri.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
        }
        return tri;
    }
};