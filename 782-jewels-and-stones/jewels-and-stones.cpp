class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> st;
        for (char x : jewels) {
            st.insert(x);
        }

        vector<int> res;
        for (char num : stones) {
            if (st.count(num)) {
                res.push_back(num);
            }
        }

        return res.size();
    }
};