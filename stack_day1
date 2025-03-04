class Solution {
  public:
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        
        // Your code here
        int i=0;
        int n=s.size();
        stack<char> st;
        string ans="";
        while(i<n){
            if((s[i]>='A' && s[i]<='Z' ) || (s[i]>='a' && s[i]<='z' ) || (s[i]>='0' && s[i]<='9' )){
                ans+=s[i];
            }
            else if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans=ans+st.top();
                    st.pop();
                }
                
            st.pop();    
            }
            else{
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        
        return ans; 
        
    }
};

