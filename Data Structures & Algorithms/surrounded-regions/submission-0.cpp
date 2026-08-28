class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Duyệt hàng trên và hàng dưới
        for (int c = 0; c < n; c++) {
            dfs(board, 0, c);
            dfs(board, m - 1, c);
        }

        // Duyệt cột trái và cột phải
        for (int r = 0; r < m; r++) {
            dfs(board, r, 0);
            dfs(board, r, n - 1);
        }

        // O còn lại là vùng bị bao quanh
        // T là O không bị bao quanh
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        // Kiểm tra ngoài biên
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        // Không phải O
        if (board[r][c] != 'O') {
            return;
        }

        // Đánh dấu O này không bị bắt
        board[r][c] = 'T';

        // 4 hướng
        dfs(board, r - 1, c); // lên
        dfs(board, r + 1, c); // xuống
        dfs(board, r, c - 1); // trái
        dfs(board, r, c + 1); // phải
    }
};