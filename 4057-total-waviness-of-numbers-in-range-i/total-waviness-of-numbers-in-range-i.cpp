class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int rslt = 0;
        for (int x = num1; x <= num2; x++) {
            string strg = to_string(x);
            for (int i = 1; i + 1 < strg.size(); i++) {
                if ((strg[i] > strg[i - 1] && strg[i] > strg[i + 1]) ||
                    (strg[i] < strg[i - 1] && strg[i] < strg[i + 1])) {
                    rslt++;
                }
            }
        }
        return rslt;
    }
};