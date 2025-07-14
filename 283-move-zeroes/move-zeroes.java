class Solution {
    public void swap(int a,int b){
        int temp=a;
        a=b;
        b=temp;
    }
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
 if (j == -1) return;
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                // we cant swap , as we want to make actual value interchange , like pass-by-value, not pass-by- refrence
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }

//---------
        // int[] temp=new int[n];
        // int x=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //         temp[x]=nums[i];
        //         x++;
        //     }
        // }
        // for(int i=x;i<n;i++){
        //     temp[i]=0;
        // }
        // for(int i=0;i<n;i++){
        //     nums[i]=temp[i];
        // }
    }
}