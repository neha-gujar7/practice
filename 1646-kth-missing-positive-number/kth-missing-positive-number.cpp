class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
             int nott = arr[m] - (m + 1);

            if(nott < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return l+k;
    }
};