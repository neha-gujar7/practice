class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left=1;
        int right=x;
        int result=0;
        
        while(left<=right){
            int mid = left + (right - left) / 2; 
            if(mid<=x/mid){
                left=mid+1;
                result=mid;
            }
            else{
                right=mid-1;
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x == 0 || x == 1) return x; // Handle base cases

//         int left = 1, right = x, result = 0;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2; // Avoid overflow
//             if ((long long)mid * mid == x) return mid; // Found exact sqrt
//             if ((long long)mid * mid < x) {
//                 result = mid; // Store possible answer
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return result;
//     }
// };
