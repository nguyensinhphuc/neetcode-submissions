class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col, diag1, diag2;
    int n;

    void backtrack(int row) {
        // Đã đặt đủ n quân hậu
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // Kiểm tra cột
            if (col[c])
                continue;

            // Đường chéo chính: row - col
            if (diag1[row - c + n - 1])
                continue;

            // Đường chéo phụ: row + col
            if (diag2[row + c])
                continue;

            // Đặt quân hậu
            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            // Sang hàng tiếp theo
            backtrack(row + 1);

            // Quay lui
            board[row][c] = '.';
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0);

        return ans;
    }
};