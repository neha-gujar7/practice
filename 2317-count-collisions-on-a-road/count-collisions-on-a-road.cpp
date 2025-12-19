class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int res = 0;
        bool acc = false;

        for (int i = 1; i < n; i++) {
            if (directions[i] == 'L') {
                if (directions[i - 1] != 'L' || acc) {
                    res += 1;
                    acc = true;
                }
            }
        }

        acc = false;
        for (int i = n - 2; i >= 0; i--) {
            if (directions[i] == 'R') {
                if (directions[i + 1] != 'R' || acc) {
                    res += 1;
                    acc = true;
                }
            }
        }

        return res;
    }
};
