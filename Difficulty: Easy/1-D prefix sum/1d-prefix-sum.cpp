class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        // code here
         int n=arr.size();
        vector<int> v(n);
        v[0]=arr[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+arr[i];
        }
        return v;
    }
};