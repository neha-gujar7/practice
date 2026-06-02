class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=1, r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m*m==n) return m;
            else if(m*m>n) r=m-1;
            else l=m+1;
        }
        return l-1;
    }
};