class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        queue<int> q;
        vector<bool> sp(n, false);
        vector<int> d(n, 0);
        sp[k] = true;
        q.push(k);

        vector<int> ad[n];
        for (auto i : invocations) {
            int u = i[0];
            int v = i[1];
            ad[u].push_back(v);
            d[v]++;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : ad[x]) {
                d[i]--;
                if (!sp[i]) {
                    q.push(i);
                    sp[i] = true;
                }
            }
        }
        vector<int> ans;
        bool p = false;
        for (int i = 0; i < sp.size(); i++) {
            if (sp[i] && d[i] > 0) {
                p = true;
                // ans.push_back(i);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!sp[i])
                ans.push_back(i);
        }
        if (p) {
            vector<int> v(n);
            for (int i = 0; i < n; i++) {
                v[i] = i;
            }
            return v;
        }

        return ans;
    }
};