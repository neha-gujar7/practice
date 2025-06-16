class Solution {
public:
    int maximumDifference(vector<int>& nums) {
//--------------brute force-------------------------------------------------
        // int maxi=-1;
        
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]<nums[j] && i<j){
        //             maxi=max(maxi,abs(nums[j]-nums[i]));
        //         }
        //     }            
        // }

        // return maxi;

//-------------------------trying optimal-----------------------

    int mini=nums[0];
    int diff=-1;
    for(int i=0;i<nums.size();i++){
       if(nums[i]>mini){
        diff=max(diff, nums[i]-mini);
       }
       else{
        mini=nums[i];
       }
    }
    return diff;
        
    }
};