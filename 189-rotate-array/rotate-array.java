class Solution {
    public void reverse(int[] nums, int i, int j){
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
        if(k==0) return;
        
        // int[] temp=new int[k];
        // for(int i=0;i<k;i++){
        //     temp[i]=nums[n+i-k];
        // }
        // int j=n-1;
        // for(int i=n-k-1;i>=0;i--){
        //     nums[j]=nums[i];
        //     j--;
        // }

        // for(int i=0;i<k;i++){
        //     nums[i]=temp[i];
        // }

        //optimal
        reverse(nums, 0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
}


