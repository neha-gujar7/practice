class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            pair<double, int> p = pq.top();

            double curProb = p.first;
            int u = p.second;
            pq.pop();

            if (u == end_node)
                return curProb;

            if (curProb < prob[u])
                continue;
            
            for (auto x : adj[u]) {
                int v = x.first;
                double p = x.second;

                double newProb = curProb * p;

                if (newProb > prob[v]) {
                    prob[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }
        return 0.0;
    }
};