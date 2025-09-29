// User function Template for C++
class Solution {
  public:
  
  string help(string& s,int i,int j){
       if(i>=j) return s;
        swap(s[i],s[j]);
        i++;
        j--;
        return help(s,i,j);
  }
    string reverseString(string& s) {
        // code here
        int n=s.size();
       
        return help(s,0,n-1);
    }
};
