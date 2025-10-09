class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        set<int> s(friends.begin(), friends.end());  // check if element is in friends
        vector<int> res;

        for(int x : order) {   // iterate in the order of 'order'
            if(s.find(x) != s.end()) {
                res.push_back(x);
            }
        }

        return res;
    }
};
