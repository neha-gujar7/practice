class Solution {
public:
int fxn(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuratio){
        int n = landStartTime.size(), m = waterStartTime.size();
        int x = INT_MAX;
        int y = INT_MAX;

        for (int i = 0; i < n; i++) {
            x = min(x, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; i++) {
            y = min(y, max(x, waterStartTime[i]) + waterDuratio[i]);
        }
        return y;
                           }
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        return min(fxn(landStartTime, landDuration, waterStartTime, waterDuration),
        fxn(waterStartTime, waterDuration,landStartTime, landDuration));

    }
};