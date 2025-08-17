class Solution {
public:
    int BS(vector<int>& nums, int l,int r, int target) {
        int n = nums.size();
        // int l = 0;
        // int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                // pivot is in right half
                l = mid + 1;
            } else {
                // pivot is in left half (including mid)
                r = mid;
            }
        }

        int pivot = l;
        if(target >=nums[pivot] && target<=nums[n-1] ) return BS( nums, pivot, n-1,target);
         
        return BS(nums, 0, pivot-1,target);

    }
};