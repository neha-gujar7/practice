class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(int i, int j, vector<vector<int>>& hight, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        for (auto &d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] 
                && hight[ni][nj] >= hight[i][j]) {
                dfs(ni, nj, hight, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hight) {
        n = hight.size();
        m = hight[0].size();
        
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        
       
        for (int j = 0; j < m; j++) dfs(0, j, hight, pac);
        for (int i = 0; i < n; i++) dfs(i, 0, hight, pac);
        
    
        for (int j = 0; j < m; j++) dfs(n-1, j, hight, atl);
        for (int i = 0; i < n; i++) dfs(i, m-1, hight, atl);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
