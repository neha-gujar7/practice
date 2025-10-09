class Solution {
public:
    long long minTime(vector<int>& s, vector<int>& m) {
        // long long minTime(vector<int>& s, vector<int>& m) {
        int n = s.size();
        vector<long long> t(n);
        for (int j : m) {
            long long c = 0;
            for (int i = 0; i < n; i++) 
                c = max(c, t[i]) + 1LL*s[i]*j;
            t[n-1] = c;
            for (int i = n-2; i >= 0; i--) 
                t[i] = t[i+1] - 1LL*s[i+1]*j;
        }
        return t[n-1];
    }
    
};