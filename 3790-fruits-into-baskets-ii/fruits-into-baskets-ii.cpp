class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for (int i : fruits) {
            for (int j=0; j<baskets.size(); ++j) {
                if (baskets[j]>=i) {
                    baskets.erase(baskets.begin() + j); break;
                }
            }
        } 
        return baskets.size();
    }
};