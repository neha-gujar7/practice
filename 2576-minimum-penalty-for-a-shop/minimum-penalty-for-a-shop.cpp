class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int penal = 0;
        for (char c : customers) {
            if (c == 'Y') penal++;
        }
        int minPen = penal;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            // opening hour j-1
            if (customers[j - 1] == 'Y') {
                penal--;   // closed+Y → open+Y (penalty removed)
            } else {
                penal++;   // closed+N → open+N (penalty added)
            }

            if (penal < minPen) {
                minPen = penal;
                ans = j;
            }
        }

        return ans;
    }
};
