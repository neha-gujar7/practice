// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int lt=0;
        int rt=n-1;
        int maxi=-1;
        while(lt<=rt){
            int mid=lt+(rt-lt)/2;
            
            if(arr[mid]>=x) {
                maxi=mid; 
                rt=mid-1;
               
            }
            else  lt=mid+1;
        }
        return maxi;
    }
};