class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
         if(sum > 9 * num) return "";

        int nin=sum/9;
        int rem=sum%9;
        string ans(nin,'9');
        if(rem>0){
            ans+=(rem+'0');
        }
        while(ans.length()<num){
            ans+='0';
        }
        return ans;
    }
};