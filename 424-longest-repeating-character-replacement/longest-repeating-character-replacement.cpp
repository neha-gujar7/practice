class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxi = -1;
        int ans = 0;
        while (r < s.size()) {
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            int len = r - l + 1;
            if (len - maxi > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};