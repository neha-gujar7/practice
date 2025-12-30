class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int s1 = 0, s2 = 0, c = 0;
        int m = grid[0].size();
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (magic(grid, i, j)) {
                    c++;
                }
            }
        }
        return c;
    }

    bool magic(vector<vector<int>>& grid, int r, int c) {
        // check for 1 to 9 , lse false;
        //  check for no duplicates;
        //  so can use undirected map;
        if(grid[r+1][c+1] != 5) return false;
//  yhis is optimal line
        unordered_map<int, int> mp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || mp.count(num)) {
                    return false;
                } else {
                    // mp.insert(num);  it is wrong
                    mp[num] = 1;
                }
            }
        }

        // for rows

        int rsum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        // int csum=grid[r][c]+grid[r+1][c]+grid[r+2][c];
        // int dsum=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+1];
        // int adsum=grid[r][c]+grid[r+1][c-1]+grid[r+2][c-2];

        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] !=
                rsum)
                return false;
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] !=
                rsum)
                return false;
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != rsum)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != rsum)
            return false;
        return true;

        // for diagonals check
        //  for(int i=)
    }
};