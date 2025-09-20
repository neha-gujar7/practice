class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0;
        int r=0;
        int maxi=-1;
    
        map<char,int> mp;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]]==0) {
                    mp.erase(s[l]);
                }
                
                l++;
            }
            if (mp.size() == k) {
                maxi = max(maxi, r - l + 1);
            }
             r++;
            
        }
        return maxi;
    }
};