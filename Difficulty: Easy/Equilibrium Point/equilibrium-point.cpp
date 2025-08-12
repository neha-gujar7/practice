class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        
        //---------brute force------- 
        int n=arr.size();
        
    //   for(int i=0;i<n;i++){
    //       int left=0;
    //       int right=0;
           
    //       for(int j=0;j<i;j++){
    //           left+=arr[i];
    //       }
           
    //       for(int j=i+1;j<n;j++){
    //           left+=arr[i];
    //       }
           
    //       if(right==left) return i;
    //   }
        
    //     return -1;
    
    //better approach
    
    
    vector<int> pre(n);
     vector<int> suf(n);
      pre[0] = arr[0];
    suf[n - 1] = arr[n - 1];
     for(int i=1;i<n;i++){
         pre[i]=pre[i-1]+arr[i];
     }
     
     for(int i=n-2;i>=0;i--){
         suf[i]=suf[i+1]+arr[i];
     }
     
     
     for(int i=0;i<n;i++){
         if(pre[i]==suf[i]){
             return i;
         }
     }
    return -1;
        
        
    }
};