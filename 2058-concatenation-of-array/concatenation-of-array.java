class Solution {
    public int[] getConcatenation(int[] nums) {
        // int[] ans(2*nums.length());->wrong way
        int n=nums.length;
        int[] ans = new int[2 * nums.length];  //correct one 
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];

        }
        return ans;
    }
}