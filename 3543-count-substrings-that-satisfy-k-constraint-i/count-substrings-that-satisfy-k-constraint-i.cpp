class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l=0,r=0,zero=0,one=0,ans=0;

        while(r<s.size()){
            if(s[r]=='0') zero++;
            if(s[r]=='1') one++;

            while(zero>k && one>k){
                if(s[l]=='0') zero--;
                if(s[l]=='1') one--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;

        
    }
};