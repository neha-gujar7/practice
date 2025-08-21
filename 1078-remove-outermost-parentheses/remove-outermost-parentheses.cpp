class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for(char a:s){
            if(a=='('){
                if(count>0) ans+=a;
                count++;
            }
            else{
                count--;
                if(count>0) ans+=a;
            }
        }
        return ans;
    }
};