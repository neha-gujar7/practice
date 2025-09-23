class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int maxi=n;
        
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]>=target){
                maxi=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return maxi;
        
    }
};
