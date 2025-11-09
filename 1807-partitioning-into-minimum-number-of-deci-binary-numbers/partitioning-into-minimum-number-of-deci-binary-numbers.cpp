class Solution {
public:
    int minPartitions(string n) {
        //---------brute
        // int c=0;

        // while(true){
        //     bool b=true;
        //     for(int i=0;i<n.size();i++){
        //         if(n[i]>'0'){
        //             n[i]--;
        //             b=false;
        //         }

        //     }
        //     if(b) break;
        //     c++;
        // }
        // return c;

        //optimal----------
        char mx = '0';
        for(char c : n){
            mx =max(mx,c) ;
        }
        return mx - '0'; 
    }
};