class Solution {
  public:
  
  // lower_bound → first index where arr[i] >= x
  int lower(vector<int>& arr, int x) {
      int n = arr.size();
      int lt = 0, rt = n - 1, ans = n;
      
      while (lt <= rt) {
          int mid = lt + (rt - lt) / 2;
          
          if (arr[mid] >= x) {
              ans = mid;
              rt = mid - 1;
          } else {
              lt = mid + 1;
          }
      }
      return ans;
  }
  
  // upper_bound → first index where arr[i] > x
  int upper(vector<int>& arr, int x) {
      int n = arr.size();
      int lt = 0, rt = n - 1, ans = n;
      
      while (lt <= rt) {
          int mid = lt + (rt - lt) / 2;
          
          if (arr[mid] > x) {   // only difference
              ans = mid;
              rt = mid - 1;
          } else {
              lt = mid + 1;
          }
      }
      return ans;
  }
  
  vector<int> find(vector<int>& arr, int x) {
      int first = lower(arr, x); 
      int last = upper(arr, x) - 1; // last occurrence
      if (first == arr.size() || arr[first] != x) {
          return {-1, -1}; // not found
      }
      return {first, last};
  }
};
