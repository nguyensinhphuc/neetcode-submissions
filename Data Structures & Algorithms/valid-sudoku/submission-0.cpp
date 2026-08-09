class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int x = board[i][j] - '1';
                int b = (i / 3) * 3 + j / 3;

                if (row[i][x] || col[j][x] || box[b][x])
                    return false;

                row[i][x] = true;
                col[j][x] = true;
                box[b][x] = true;
            }
        }

        return true;
    }
};