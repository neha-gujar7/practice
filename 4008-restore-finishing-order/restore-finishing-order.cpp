class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        set<int> st;
        for (int x : friends) {
            st.insert(x);
        }

        vector<int> res;
        for (int num : order) {
            if (st.count(num)) {
                res.push_back(num);
            }
        }

        return res;
    }
};
