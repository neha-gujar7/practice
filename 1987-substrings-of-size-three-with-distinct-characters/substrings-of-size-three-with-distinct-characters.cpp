class Solution {
public:
    int countGoodSubstrings(string s) {
        // int l=0;
        // int r=2;
        // int cn=0;
        // while(r<s.size()){
        //     if(s[r-1]!=s[r-2] && s[r-1]!=s[r] && s[r-2]!=s[r]){
        //         cn++;
        //     }
        //     r++;
        // }
        // return cn;

       if (s.size() < 3) return 0;  // ✅ important check

        int count = 0;
        map<char, int> mp;

        for (int i = 0; i <= s.size() - 3; i++) {
            mp.clear(); // start fresh for each substring

            // insert 3 characters of current substring
            mp[s[i]]++;
            mp[s[i + 1]]++;
            mp[s[i + 2]]++;

            // if all are distinct
            if (mp.size() == 3) {
                count++;
            }
        }
        return count;

        
    }
};