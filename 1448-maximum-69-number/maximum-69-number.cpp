class Solution {
public:
    int maximum69Number (int num) {
       int l=0;
       string s=to_string(num);
       int n=s.size();
       int r=n-1;
       while(l<=r){
        if(s[l]=='6'){
            s[l]='9';
            break;
        }
        l++;
       } 
    //    while(r>=0){
    //     if(s[l]=='9'){
    //         s[l]='6';
    //         break;
    //     }
    //     r--;
    //    } 


       int ans=stoi(s);
       return ans;
    }
};