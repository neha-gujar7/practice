class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int ans=maxi;
        int l=1,r=maxi;
        while(l<=r){
            int m=l+(r-l)/2;
           double tot=0;
            for(int i=0;i<n;i++){
                tot+=ceil((double)(piles[i])/m);
            }
            if(tot<=h)  {
                r=m-1;
                ans=m;

            }
            else l=m+1;
            
        }
        return ans;
    }
};