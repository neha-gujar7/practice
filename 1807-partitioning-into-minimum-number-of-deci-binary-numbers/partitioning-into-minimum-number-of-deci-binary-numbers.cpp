class Solution {
public:
    int minPartitions(string n) {
        int c=0;

        while(true){
            bool b=true;
            for(int i=0;i<n.size();i++){
                if(n[i]>'0'){
                    n[i]--;
                    b=false;
                }

            }
            if(b) break;
            c++;
        }
        return c;
    }
};