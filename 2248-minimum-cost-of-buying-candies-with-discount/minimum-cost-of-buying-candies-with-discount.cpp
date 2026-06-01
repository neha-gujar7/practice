class Solution {
public:
    int minimumCost(vector<int>& cost) {
         sort(cost.begin(),cost.end());
       int n=cost.size();
        int s=0;

        int cn=0;
    //    if(n<=2){
    //     for(int i=n-1;i>=0;i--){
    //         s+=cost[i];
    //     }
    //     return s;

    //    }
      
      
       for(int i=n-1;i>=0;i--){
        cn++;
        if(cn%3!=0){
            s+=cost[i];
        }
       } 
       return s;
    }
};

