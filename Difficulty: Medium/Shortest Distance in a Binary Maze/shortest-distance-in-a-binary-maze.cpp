class Solution {
public:

    int bfs(vector<vector<int>> &grid,
            pair<int, int> source,
            pair<int, int> destination,
            vector<vector<int>> &dst) {

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {source.first, source.second}});

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;

            for (int i = 0; i < 4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == 1 &&
                    d + 1 < dst[nr][nc]) {

                    dst[nr][nc] = d + 1;

                    if (nr == destination.first &&
                        nc == destination.second) {
                        return d + 1;
                    }

                    q.push({dst[nr][nc], {nr, nc}});
                }
            }
        }

        return -1;
    }

    int shortestPath(vector<vector<int>> &grid,
                     pair<int, int> source,
                     pair<int, int> destination) {

        int n = grid.size();
        int m = grid[0].size();

        if (source == destination)
            return 0;

        if (grid[source.first][source.second] == 0 ||
            grid[destination.first][destination.second] == 0)
            return -1;

        vector<vector<int>> dst(n, vector<int>(m, 1e9));

        dst[source.first][source.second] = 0;

        return bfs(grid, source, destination, dst);
    }
};