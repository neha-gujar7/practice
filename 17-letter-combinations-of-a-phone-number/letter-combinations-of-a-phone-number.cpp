class Solution {
public:
    void gen(int i, string digits, string temp, vector<string>& ans,
             unordered_map<char, string>& mp) {
                
                if(i==digits.size()){
                    ans.push_back(temp);
                    return ;
                }

                for(char c: mp[digits[i]]){
                    gen(i+1,digits,temp+c,ans,mp);
                }

             }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string temp="";
        gen(0, digits, temp, ans, mp);
        return ans;
    }
};