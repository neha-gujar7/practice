class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        // store {start, index}
        vector<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            st.push_back({intervals[i][0], i});
        }
        sort(st.begin(), st.end());
        // for each interval, binary search on st
        for(int i = 0; i < n; i++){
            int end = intervals[i][1];
            int l = 0, r = n-1, mini_idx = -1;

            while(l <= r){
                int mid = l + (r-l)/2;
                if(st[mid].first >= end){
                    mini_idx = st[mid].second;
                    r = mid - 1; // try smaller start
                } else {
                    l = mid + 1;
                }
            }
            res[i] = mini_idx;
        }
        return res;
    }
};
