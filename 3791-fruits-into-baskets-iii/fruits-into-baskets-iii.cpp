class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size(), size = 1, res = 0;
        while (size < n) size <<= 1;
        vector<int> seg(size << 1);

        for (int i = 0; i < n; i++)
            seg[size + i] = b[i];

        for (int i = size - 1; i > 0; i--)
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);

        for (int x : f) {
            int i = 1;
            if (seg[i] < x) {
                res++;
                continue;
            }
            while (i < size)
                i = (seg[i << 1] >= x) ? (i << 1) : (i << 1 | 1);

            seg[i] = -1;
            while (i > 1) {
                i >>= 1;
                seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
            }
        }

        return res;
    }
};
