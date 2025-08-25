class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]=i;  //we are storing elements
        } 

         for(int i=0;i<n;i++){
            int num2=target-nums[i];
            if(mp.count(num2) && mp[num2]!=i){
                return {mp[num2],i};
            }
        } 
        return {};
    }
};