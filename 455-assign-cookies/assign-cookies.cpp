class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int i=0,j=0;
       int c=0;
       while(i<g.size() && j<s.size()){
        if(g[i]<=s[j]){
            i++;j++;
            c++;
        }
        // else if(g[i]>s[j]){
        //     j++;
        // }
        // else {
        //     i++;
        // }   
        else {
            j++;
        }       
       }
       return c;
    }
};