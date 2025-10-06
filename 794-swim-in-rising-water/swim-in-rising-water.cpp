class Solution {
public:
    int n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    bool vis[50][50];

    // DFS to check if we can reach (n-1, n-1) with water level <= mid
    bool canReach(vector<vector<int>>& g, int i, int j, int mid) {
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j] || g[i][j]>mid) return false;
        vis[i][j] = true;
        if(i==n-1 && j==n-1) return true;

        for(auto &d : dirs)
            if(canReach(g, i+d[0], j+d[1], mid)) return true;
        return false;
    }

    int swimInWater(vector<vector<int>>& g) {
        n = g.size();
        int l = g[0][0], r = n*n-1, ans = 0;

        // Binary search on water level
        while(l <= r) {
            int mid = l + (r-l)/2;
            memset(vis, 0, sizeof(vis));

            if(canReach(g, 0, 0, mid)) { // if path possible at this level
                ans = mid;               // store possible answer
                r = mid - 1;             // try lower level
            } else l = mid + 1;          // else go higher
        }
        return ans;
    }
};
