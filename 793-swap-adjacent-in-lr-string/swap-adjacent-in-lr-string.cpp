class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.length();
        int a = 0, b = 0;
        while (a < n || b < n) {

            while (a < n && start[a] == 'X')
                a++;
            while (b < n && result[b] == 'X')
                b++;

            if (a == n || b == n)
                return a == n && b == n;

            if (start[a] != result[b])
                return false;
            if (start[a] == 'L' && a < b)
                return false;

            if (start[a] == 'R' && a > b)
                return false;
            a++;
            b++;
        }
        return true;
    }
};