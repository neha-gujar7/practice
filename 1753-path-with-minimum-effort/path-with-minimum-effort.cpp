class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int effort = p.first;
            int r = p.second.first;
            int c = p.second.second;

            if (r == n - 1 && c == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int edge = abs(heights[nr][nc] - heights[r][c]);
                    int newEffort = max(effort, edge);
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};