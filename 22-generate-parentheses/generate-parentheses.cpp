class Solution {
public:
    void generate(int o, int c, string s, vector<string>& ans) {
        if (o == 0 && c == 0) {
            ans.push_back(s);
            return;
        }
        if(o>0){
            generate(o-1,c,s+"(",ans);
        }
        if(o<c){
            generate(o,c-1,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         generate(n,n,"",ans);
         return ans;
    }


};