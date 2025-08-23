class Solution {
public:
    // can do brute force by xoring all elements of nums
    // optimal -> by binary search
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
    
        int l = 0;
        int r = n - 1;
        if(n==1) return nums[0];
        if(nums[l]!=nums[l+1]) return nums[l];
        if(nums[r]!=nums[r-1]) return nums[r];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } 
            
            else if (mid % 2 == 0) {
                if (nums[mid] == nums[mid+1]) {
                    l = mid + 2;
                } else {
                    r=mid-1;
                }
            }


            else{
                if (nums[mid] == nums[mid -1]) {
                    l = mid + 1;
                } else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};