class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v, cost});
        }
        queue<pair<int, pair<int, int>>> q;

        // start from source
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty()) {

            auto x = q.front();
            q.pop();

            int stops = x.first;
            int node = x.second.first;
            int cost = x.second.second;
            if (stops > k)
                continue;
            // process neighbors of node
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeCost = it.second;

                if (cost + edgeCost < dist[adjNode]) {
                    dist[adjNode] = cost + edgeCost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
         if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
// TC: O(k * E)
// SC: O(V + E)