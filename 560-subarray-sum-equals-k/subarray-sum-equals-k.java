class Solution {
    public int subarraySum(int[] nums, int k) {
        int n=nums.length;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                if(sum==k){
                    count++;
                }
            }
            sum=0;
        }
        return count;
    }
}