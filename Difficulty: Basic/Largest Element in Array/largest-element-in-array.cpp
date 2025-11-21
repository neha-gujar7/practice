class Solution {
  public:
  int help(int i,int maxi,vector<int> &arr){
      if(i==arr.size()){
          return maxi;
      }
      if(maxi<arr[i] ){
          maxi=arr[i];
      }
      return  help(i+1,maxi,arr);
      
  }
    int largest(vector<int> &arr) {
    int maxi=-1;
       maxi=help(0,maxi,arr);
       return maxi;
    }
};
