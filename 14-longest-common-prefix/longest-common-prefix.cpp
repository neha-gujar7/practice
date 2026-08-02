class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());

        string s="";
        int mini=min(strs[0].size(),strs[n-1].size());
        for(int i=0;i<mini;i++){
            if(strs[0][i]==strs[n-1][i]){
                s+=strs[0][i];
            }
            else break;
        }
return s;        
            
    }
};