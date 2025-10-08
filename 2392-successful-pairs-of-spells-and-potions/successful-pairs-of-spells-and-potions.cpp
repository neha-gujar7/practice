class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long suc) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long mini = (suc + spell - 1) / spell;  // ceil(suc / spell)

            int l = 0, r = n - 1, idx = n;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (potions[m] >= mini) {
                    idx = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            ans.push_back(n - idx);
        }

        return ans;
    }
};
