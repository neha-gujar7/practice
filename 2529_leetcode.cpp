class Solution {
public:
    int maximumCount(vector<int>& nums) {

        //brute force it seems
         int pc=0,nc=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pc++;
            }
            if(nums[i]<0){
                nc++;
            }
        }
        int ans=(pc>nc)?pc:nc;

return ans;
    }
};
