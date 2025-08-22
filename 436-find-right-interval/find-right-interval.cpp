class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        // storing {start, index} as a pair for easy access
        vector<pair<int,int>> s;
        for (int i = 0; i < n; i++) {
            s.push_back({intervals[i][0], i});
        }
        // sort by starts
        sort(s.begin(), s.end());
        //  each interval, binary search in starts
        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            int l = 0, r = n - 1;
            int temp= -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (s[mid].first >= target) {
                    temp = s[mid].second; // potential answer
                    r = mid - 1; // look for smaller start
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = temp;
        }

        return ans;
    }
};
