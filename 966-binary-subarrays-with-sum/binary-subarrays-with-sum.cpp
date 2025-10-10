class Solution {
public:
int help(vector<int>& nums, int goal){
    int n=nums.size(),r=0,l=0;
        if(goal<0) return 0;
        int c=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }


        return c;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (help(nums,goal)-help(nums,goal-1));
    }
};