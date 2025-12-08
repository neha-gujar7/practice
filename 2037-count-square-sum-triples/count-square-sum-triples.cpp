class Solution {
public:
    int countTriples(int n) {
        int cn=0;
        // //  int c=
        // int c;
        // for(int a=1;a<=n;a++){
        //     for(int b=1;b<=n;b++){
        //         int c=sqrt(a*a+b*b);
        //         if(c<=n  && c*c==a*a+b*b){
        //             cn++;
        //         }
        //     }
        // }

        for(int c=1;c<=n;c++){
            int target=c*c;
            int a=1,b=c-1;

            while(a<b){
                int sum=a*a+b*b;
                if(sum<target) a++;
                else if(sum>target)  b--;
                else{
                    a++;
                    b--;
                    cn+=2;
                }
            }
            
        }

        return cn;
    }
};