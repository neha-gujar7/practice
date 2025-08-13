class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> v(n+1);
        int j=1;
        for(int i=0;i<n;i++){
            v[j]=v[j-1]+gain[i];
            j++;
        }
        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
};