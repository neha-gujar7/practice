class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);

        for(int i = 0; i < n; i++){
            int end = intervals[i][1];
            int mini_st = INT_MAX;
            int mini_idx = -1;

            for(int j = 0; j < n; j++){
                if(intervals[j][0] >= end && intervals[j][0] < mini_st){
                    mini_st = intervals[j][0];
                    mini_idx = j;
                }
            }
            res[i] = mini_idx;
        }
        return res;
    }
};
