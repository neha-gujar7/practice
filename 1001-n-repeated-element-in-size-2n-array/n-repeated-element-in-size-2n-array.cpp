class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int x = -1;
        for (auto i : mp) {
            if (i.second > 1) {
                x = i.first;
                break;
            }
        }
        return x;
    }
};