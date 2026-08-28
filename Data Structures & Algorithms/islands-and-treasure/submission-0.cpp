class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Đưa tất cả kho báu vào queue
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // 4 hướng: lên, xuống, trái, phải
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Ra ngoài grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                // Không đi qua tường
                if (grid[nr][nc] != 2147483647) {
                    continue;
                }

                // Khoảng cách mới
                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};
