class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int n=abs(x);
        int i;
        long j=0;
        while(n>0){
            i=n%10;
            j=i+j*10;
            
            if(j>INT_MAX || j<INT_MIN){
                return 0;
            }
            n/=10;
        }

        if(x==j){
            return true;
        }
        return false;











        // int n=abs(x);
        // long j=0;
        // int i;
        // while(n>0){
        //     i=n%10;
        //     j=i+j*10;
        //     if(j>INT_MAX || j<INT_MIN ){
        //         return 0;
        //       }
        //     n=n/10;       
        // }
        // if(x==j){
        //     return true;
        // }
        // return false;
    }
};