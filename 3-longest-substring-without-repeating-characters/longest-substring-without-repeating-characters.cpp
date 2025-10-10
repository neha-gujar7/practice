class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        map<char, int> mp;
        int l = 0;
        int r = 0;

        while(r<s.size()) {
            mp[s[r]]++;
            
                while(mp[s[r]]>1){
                    mp[s[l]]--;
                    l++;
                }
                maxi=max(maxi,r-l+1);
                r++;

        }
        return maxi;
    }
};