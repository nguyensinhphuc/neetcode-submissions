class Solution {
public:
    int n, m;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;

        // Đánh dấu ô này đã được thăm
        grid[i][j] = 0;

        return 1
            + dfs(grid, i + 1, j)
            + dfs(grid, i - 1, j)
            + dfs(grid, i, j + 1)
            + dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};