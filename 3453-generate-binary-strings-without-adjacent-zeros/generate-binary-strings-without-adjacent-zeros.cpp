class Solution {
public:
    void generate(int n,vector<string>& ans,string c){
        if(c.size()==n){
            ans.push_back(c);
            return ;
        }
        generate(n,ans,c+"1");
        if(c.empty() || c.back()!='0'){
            generate(n,ans,c+"0");
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n, ans, "");
        return ans;
    }
};