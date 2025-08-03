class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0, curr = 0;
        int i = 0;
        for (int j = 0; j < fruits.size(); ++j) {
            int pj = fruits[j][0], fj = fruits[j][1];
            curr += fj;
            // Shrink `i` while window exceeds step budget
            while (i <= j &&
                   (pj - fruits[i][0] +
                        min(abs(startPos - fruits[i][0]), abs(startPos - pj)) >
                    k)) {
                curr -= fruits[i][1];
                i++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};

// int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

// }
