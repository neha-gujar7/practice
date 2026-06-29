class Solution {
public:
    int dijkstra(int src, int n, vector<pair<int,int>> adj[],
                 int threshold) {

        vector<int> dist(n, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();

            int d = cur.first;
            int u = cur.second;

            if (d > dist[u]) continue;

            for (auto it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (i != src && dist[i] <= threshold)
                cnt++;
        }

        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<pair<int,int>> adj[n];

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int mn = 1e9;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int cnt = dijkstra(i, n, adj, distanceThreshold);

            if (cnt <= mn) {
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};