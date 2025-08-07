class Solution {
public:
    const int MOD=1e9+7;
    long long power(long long base, long long exp){
        long long result=1;
        base=base%MOD;
        while(exp>0){
            if(exp%2==1){
                result=(result*base)%MOD;
            }
            base=(base*base)%MOD;
            exp=exp/2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos=(n+1)/2;
        long long oddPos=n/2;
        long long evenWay=power(5,evenPos);
        long long oddWay=power(4,oddPos);
        return (evenWay*oddWay)%MOD;
    }
};