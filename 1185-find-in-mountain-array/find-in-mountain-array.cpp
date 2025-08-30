/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // Binary search helper
    int BS(MountainArray& mountainArr, int l, int r, int target, bool asc) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;

            if (asc) { // Ascending part
                if (val < target) l = mid + 1;
                else r = mid - 1;
            } else {   // Descending part
                if (val < target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;

        // 1. Find peak index
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int peak = l;

        // 2. Binary search on ascending part
        int idx = BS(mountainArr, 0, peak, target, true);
        if (idx != -1) return idx;

        // 3. Binary search on descending part
        return BS(mountainArr, peak + 1, n - 1, target, false);
    }
};
