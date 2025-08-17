class Solution {
  public:
  int first(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                r = mid - 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int last(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int x=first(arr,target);
        int y=last(arr, target);
        if(x==-1 && y==-1) return 0;
        return y-x+1;
    }
};
