class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int lt=0;
        int rt=n-1;
        int maxi=n;
        while(lt<=rt){
            int mid=lt+(rt-lt)/2;
            
            if(arr[mid]>target) {
                maxi=mid; 
                rt=mid-1;
            //   return arr[mid];
            }
            else  lt=mid+1;
        }
        return maxi;
    }
};
