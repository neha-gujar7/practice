// class Solution {
// public:
//     // int search(vector<int>& nums, int target) {
//     //     int low=0;
//     //     int high=nums.size()-1;
//         // while(low<=high){
//         //     int mid = (high + low) / 2;            
//         //     if(nums[mid]==target){
//         //         return mid;
//         //     }
//         //     if(nums[mid]<target){
//         //         low=mid+1;
//         //     }
//         //     else{
//         //         high=mid-1;
//         // //     }
//         // }
//         // return -1;  


//         // recursive approach 

        
// int search(vector<int>& nums, int low, int high, int target) {
        
        
//         if(low>high){
//             return -1;
//         }

//         if(low<=high){
//             int mid = (high + low) / 2;
//             if(nums[mid]==target){
//                 return mid;
//             }

//             if(target>nums[mid]){
//                 return search(nums,mid+1,high,target);
//             }

//             if(target<nums[mid]){
//                 return search(nums,low,mid-1,target);
//             }
//         }
//         return 0;
//    }
//     int search(vector<int>& nums, int target){

//         return search(nums,0,nums.size()-1,target);
//     }
// };

class Solution{
public:
    int search(vector<int> &nums,int target){

        int n=nums.size();
        int lt=0;
        int rt=n-1;
        while(lt<=rt){
            int mid=lt+(rt-lt)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) lt=mid+1;
            else rt=mid-1;
        }
        return -1;

    }
};