class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : st) {
            if (!st.count(num - 1)) { // start of sequence
                int curr = num;
                int ln = 1;
                while (st.count(curr + 1)) {
                    curr++;
                    ln++;
                }
                ans = max(ans, ln);
            }
        }
        return ans;
    }
};
