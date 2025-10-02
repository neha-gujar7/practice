class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem_full_bot=0;
        int extra_full_bot=0;

        int cons=numBottles;
        int empty=numBottles;

        while(empty>=numExchange){
            
            extra_full_bot=empty/numExchange;
            rem_full_bot=empty%numExchange;

            cons+=extra_full_bot;
            empty=extra_full_bot+rem_full_bot;
        }

        return cons;
        

    }
};