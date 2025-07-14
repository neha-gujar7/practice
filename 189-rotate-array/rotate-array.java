class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
        if(k==0) return;
        int x=0;
        int[] temp=new int[n];
        for(int i=0;i<k;i++){
            temp[i]=nums[n+i-k];
        }
        int j=n-1;
        for(int i=n-k-1;i>=0;i--){
            nums[j]=nums[i];
            j--;
        }

        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
}


