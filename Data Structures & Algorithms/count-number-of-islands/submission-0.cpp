class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // Ra ngoài
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Không phải đất
        if (grid[r][c] != '1')
            return;

        // Đánh dấu đã thăm
        grid[r][c] = '0';

        // 4 hướng
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    // Tìm thấy một đảo mới
                    ans++;

                    // Xóa toàn bộ đảo đó khỏi grid
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};