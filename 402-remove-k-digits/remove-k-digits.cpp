class Solution {
public:
    string removeKdigits(const std::string& num, int k) {
        if(num.size()==k){
            return "0";
        }
       int digitsToRemove=k;
       stack<char> stk;
       for(int i=0;i<num.size();i++){
      
       while(!stk.empty() && digitsToRemove>0 && stk.top()-'0'>num[i]-'0'){
        cout<<stk.top()<<" "<<num[i]<<" "<<digitsToRemove<<endl;
        stk.pop();
        digitsToRemove--;
       }
       stk.push(num[i]);
       }
       while(stk.size()>1 && digitsToRemove>0){
        stk.pop();
        digitsToRemove--;
       }
       string ans="";
       while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
       }
       reverse(ans.begin(), ans.end());
       int j=0;
       for(int i=0;i<ans.size();i++){
        if(ans[i]=='0'){
            j++;
        }
        else{
            break;
        }
       }
       if(j==ans.size()){
        return "0";
       }
       ans=ans.substr(j,ans.size()-j+1);
      
       return ans;
    }
};

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         int n=num.size();
//         stack<char> st;
//         int i=1;
//        st.push(num[0]);
//         while(i<n){
//             if(!st.empty()) {
//                 if(num[i]>=st.top()){
//                     st.push(num[i]);
//                 }
//                 else {
//                     st.pop();
//                     k--;
//                 }
//             }
//             i++;
//         }
//         string ans="";
//         for(int i=0;i<st.size();i++){
//             ans[i]+=st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };