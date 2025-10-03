class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    int trapRainWater(vector<vector<int>>& h) {
        int rows = h.size(), cols = h[0].size();
        priority_queue<P, vector<P>, greater<>> pq;
        vector<vector<bool>> vis(rows, vector<bool>(cols,false));

        for (int r = 0; r < rows; r++) {
            for (int c : {0, cols-1}) {
                pq.push({h[r][c], {r,c}});
                vis[r][c] = true;
            }
        }

        for (int c = 0; c < cols; c++) {
            for (int r : {0, rows-1}) {
                pq.push({h[r][c], {r,c}});
                vis[r][c] = true;
            }
        }

        int water = 0;
        while (!pq.empty()) {

            
            auto [ht, cell] = pq.top(); pq.pop();
            int r = cell.first, c = cell.second;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr>=0 && nr<rows && nc>=0 && nc<cols && !vis[nr][nc]) {
                    water += max(0, ht - h[nr][nc]);
                    pq.push({max(ht, h[nr][nc]), {nr,nc}});
                    vis[nr][nc] = true;
                }
            }



        }
        return water;
    }
};
