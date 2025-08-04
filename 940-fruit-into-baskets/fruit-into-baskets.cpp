class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fq;
        int l = 0;
        int maxi = 0;

        for (int r = 0; r < fruits.size(); r++) {
            fq[fruits[r]]++;

            while (fq.size() > 2) {
                fq[fruits[l]]--;
                if (fq[fruits[l]] == 0) {
                    fq.erase(fruits[l]);
                }
                l++;
            }

            int checklen = r - l + 1;
            maxi = max(maxi, checklen);
        }

        return maxi;
    }
};
