class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Đưa tất cả quả thối vào queue
        // và đếm số quả tươi
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int directions[4][2] = {
            {-1, 0}, // lên
            {1, 0},  // xuống
            {0, -1}, // trái
            {0, 1}   // phải
        };

        // BFS
        while (!q.empty() && fresh > 0) {

            // Số quả thối ở thời điểm hiện tại
            int size = q.size();

            // Một vòng = một phút
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Ngoài grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Không phải quả tươi
                    if (grid[nr][nc] != 1) {
                        continue;
                    }

                    // Làm quả tươi bị thối
                    grid[nr][nc] = 2;
                    fresh--;

                    // Đưa vào queue để phút sau tiếp tục lây
                    q.push({nr, nc});
                }
            }

            minutes++;
        }

        // Vẫn còn quả tươi → không thể làm thối hết
        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};