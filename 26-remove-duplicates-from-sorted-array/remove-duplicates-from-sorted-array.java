class Solution {
    public int removeDuplicates(int[] nums) {
        int cnt=0;
        int n=nums.length;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[cnt]){
                cnt++;
                nums[cnt]=nums[i];
            }
        }
        return cnt+1;
    }
}