class Solution {
    public void swap(int a,int b){
        int temp=a;
        a=b;
        b=temp;
    }
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int j=1;

        int[] temp=new int[n];
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp[x]=nums[i];
                x++;
            }
        }
        for(int i=x;i<n;i++){
            temp[i]=0;
        }
        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
}