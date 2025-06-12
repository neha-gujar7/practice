class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        if(abs(nums[0]-nums[nums.size()-1])>maxi){
            maxi=abs(nums[0]-nums[nums.size()-1]);
        }
        for(int i=1;i<nums.size();i++){
            
            if(abs(nums[i]-nums[i-1])>maxi){
                maxi=abs(nums[i]-nums[i-1]);
            }
        }
        return maxi;
    }
};