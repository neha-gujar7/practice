class Solution {
public:
    int maxDiff(int num) {
        string s1 = to_string(num);

        // ----- MAXI -----
        string s = s1;
        char a = 0;

        // Find the first digit (from left) which is not '9'
        for (char c : s1) {
            if (c != '9') {
                a = c;
                break;
            }
        }

        // Replace all such digits with '9'
        if (a) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == a) {
                    s[i] = '9';
                }
            }
        }

        int maxi = stoi(s);

        // ----- MINI -----
        string t = s1;
        char b = 0;

        // For minimizing, if first digit is not '1', replace it with '1'
        if (t[0] != '1') {
            b = t[0];
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == b) {
                    t[i] = '1';
                }
            }
        } else {
            // Otherwise, find a digit (not at index 0) to replace with '0'
            for (int i = 1; i < t.size(); i++) {
                if (t[i] != '0' && t[i] != '1') {
                    b = t[i];
                    break;
                }
            }
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == b) {
                    t[i] = '0';
                }
            }
        }

        int mini = stoi(t);

        return maxi - mini;
    }
};
