class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int c=numBottles;
        int eb=numBottles;
        // if(numBottles<=numExchange) return 1;
        // numBottles=0;
        while(eb>=numExchange){
            eb=eb-numExchange;
            numExchange++;
            eb+=1;
            c+=1;
        }
        return c;
    }
};