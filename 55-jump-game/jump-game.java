class Solution {
    public boolean canJump(int[] nums) {
        // int maxjump=0;
        int n=nums.length;
        // for(int i=0;i<n;i++){
        //     if(i>maxjump){
        //         return false;
        //     }
        //     else{
        //         maxjump=Math.max( maxjump,i+nums[i]);
        //     }
        // }
        // return true;

        boolean ans=true;
        int maxReach=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=maxReach){
                ans=true;
                maxReach=1;
            }
            else{
                ans=false;
                maxReach++;
            }
  
        }
        return ans;

        
    }
}