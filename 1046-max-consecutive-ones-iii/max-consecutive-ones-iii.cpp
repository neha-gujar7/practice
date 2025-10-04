class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        // int cur = r-+1;

        int l=0;
        int r=0;
        int x=k;
        while(r<nums.size()){
            if(nums[r]==0){
                k--;
            }
            while(k<0){
                k=k+1-nums[l];
                l++;
            }
            if(k>=0){
                maxi=max(maxi,r-l+1);

            }
            r++;
        }
        return maxi;
      
    }
};