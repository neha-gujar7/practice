class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int lt=0;
        int rt=n-1;
        int maxi=-1;
        while(lt<=rt){
            int mid=lt+(rt-lt)/2;
            // as we have t ofind maximum but <=x , so we have to take a maximum number 
            if(arr[mid]<=x) {
                maxi=mid; 
                lt=mid+1;
            }
            else rt=mid-1;
        }
        return maxi;
    }
};
