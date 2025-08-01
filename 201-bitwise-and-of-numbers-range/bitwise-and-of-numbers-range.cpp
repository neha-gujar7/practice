class Solution {
public:
// int decimalToBinary(int n) {
//     int binary = 0;
//     int place = 1;

//     while (n > 0) {
//         int rem = n % 2;
//         binary += rem * place;
//         place *= 10;
//         n /= 2;
//     }

//     return binary;
// }
    int rangeBitwiseAnd(int left, int right) {
        // int l=decimalToBinary(left);
        // int r=decimalToBinary(right);
        int count_shift=0;
        while(left<right){
            right>>=1;
            left>>=1;
            count_shift++;
        }
        return right<<=count_shift;
    }
};