class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int c=numBottles;
        int eb=numBottles;
      
        while(eb>=numExchange){
            eb=eb-numExchange+1;
            numExchange++;
            // eb+=1;
            c+=1;
        }
        return c;
    }
};