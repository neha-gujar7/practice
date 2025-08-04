class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return false;
        }
        int x=0;
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
                  x=i;
            }
           
        }
        //checking for index x = 0 or n-1
        if(x==0 || x==n-1){
            return false;
        }

       //checking for increasing order
        for(int i=0;i<x;i++){
            if(arr[i]>=arr[i+1]){
                return false;
            }
        }
        for(int i=x;i<n-1;i++){
            if(arr[i]<=arr[i+1]){
                return false;
            }
        }
        return true;
    }
};