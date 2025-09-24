class Solution {
public:
    int part(vector<int>& nums, int l, int h) {
        int piv = nums[l];
        int i = l;
        int j = h;

        while (i < j) {
            while (i <= h && nums[i] <= piv)
                i++;

            while (j >= l && nums[j] > piv)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }

        swap(nums[l], nums[j]);
        return j;
    }
    int qs(vector<int>& nums, int l, int h, int k) {
        int p = part(nums, l, h);

        if (p == k)
            return nums[p];
        else if (k < p)
            return qs(nums, l, p - 1, k);
        else
            return qs(nums, p + 1, h, k);
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
vector<int> v;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        v.push_back(matrix[i][j]);
    }
}
        return qs(v,0,v.size()-1,k-1);
    }
};