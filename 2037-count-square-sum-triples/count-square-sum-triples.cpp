class Solution {
public:
    int countTriples(int n) {
        int cn=0;
        // //  int c=
        // int c;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int c=sqrt(a*a+b*b);
                if(c<=n  && c*c==a*a+b*b){
                    cn++;
                }
            }
        }
        return cn;
    }
};