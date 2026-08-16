class Solution {
public:
    int m, n;
    vector<vector<int>> heights;
    vector<vector<bool>> pacific, atlantic;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            // Đi ngược dòng nước:
            // chỉ đi sang ô có độ cao >= ô hiện tại
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<bool>(n, false));
        atlantic.assign(m, vector<bool>(n, false));

        // Pacific: hàng trên cùng + cột trái
        for (int c = 0; c < n; c++) {
            dfs(0, c, pacific);
        }

        for (int r = 0; r < m; r++) {
            dfs(r, 0, pacific);
        }

        // Atlantic: hàng dưới cùng + cột phải
        for (int c = 0; c < n; c++) {
            dfs(m - 1, c, atlantic);
        }

        for (int r = 0; r < m; r++) {
            dfs(r, n - 1, atlantic);
        }

        vector<vector<int>> ans;

        // Ô nào đi được tới cả 2 đại dương
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};