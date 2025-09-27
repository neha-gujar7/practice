// User function template for C++
class Solution {
  public:
  int help(vector<int>& arr,int n){
    //   int n=arr.size();
        if(n==0) return 0;
        return (arr[n-1]+help(arr,n-1));
  }
  
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        
        // code here
        int n=arr.size();
        return help(arr,n);
       
    }
};