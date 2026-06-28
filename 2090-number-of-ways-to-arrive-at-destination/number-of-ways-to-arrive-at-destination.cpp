class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<long long> dst(n, LLONG_MAX);
        vector<long long> ways(n + 1, 0);
        vector<pair<int, int>> adj[n + 1];

         int mod = 1e9 + 7;
        for (auto i : roads) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

       priority_queue<pair<long long, int>,
               vector<pair<long long, int>>,
               greater<pair<long long, int>>> q;
        dst[0] = 0;
        ways[0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
           long long dis = x.first;
            int nod = x.second;

             if (dis > dst[nod])
                    continue;
            for (auto it : adj[nod]) {
                int adnod = it.first;
                int egwt = it.second;
               
                if (dis + egwt < dst[adnod]) {
                    dst[adnod] = dis + egwt;
                    ways[adnod] = ways[nod];
                    q.push({dst[adnod], adnod});
                } else if (dis + egwt == dst[adnod]) {
ways[adnod] = (ways[adnod] + ways[nod]) % mod;                }
            }
        }
        return ways[n - 1];
    }
};