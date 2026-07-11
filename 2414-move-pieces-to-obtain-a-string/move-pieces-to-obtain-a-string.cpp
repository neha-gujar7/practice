class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int a=0,b=0;
       
        while(a<n || b<n){
            while(a<n && start[a]=='_') a++;
            while(b<n && target[b]=='_') b++;
            if(a==n && b==n) return true;
            if(a==n || b==n) return false;

            if(start[a]=='L' && a<b) return false;
            if(start[a]=='R'  && a>b) return false;

            if(start[a]!=target[b])  return false;
            a++;
            b++;

        }
        return true;
    }
};