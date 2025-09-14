class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lastSum = 0;
        for (int i = n - 1; i >= n-k; i--) {
            lastSum += cardPoints[i];
        }

        int maxiSum = lastSum;
        for (int i = 0; i < k; i++) {
            lastSum += cardPoints[i];
            lastSum -= cardPoints[n - k + i];
            maxiSum = max(maxiSum, lastSum);
        }

        return maxiSum;
    }
};