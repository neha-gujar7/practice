class Solution {
public:
    int findNextIndex(int i, vector<vector<int>>& events) {
        int left = i + 1, right = events.size() - 1;
        int ans = -1;
        int need = events[i][1] + 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] >= need) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = events[i][2];
            int idx = findNextIndex(i, events);
            if (idx != -1) val += suffixMax[idx];
            ans = max(ans, val);
        }

        return ans;
    }
};
