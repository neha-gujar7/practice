class Solution {
public:
    bool func(vector<int> &d, double h, int sp) {
        double time = 0;
        for (int i = 0; i < d.size(); i++) {
            time += (double)d[i] / sp;
            if (time > h) return false;
            if (i != d.size() - 1) time = ceil(time);
        }
        return true;
    }

    int minSpeedOnTime(vector<int>& d, double h) {
        int l = 1, r = 1e7, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (func(d, h, m)) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
