class Solution {
public:
    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (cur->child[idx] == nullptr) {
                cur->child[idx] = new Node();
            }

            cur = cur->child[idx];
        }

        // Lưu luôn từ tại node cuối
        cur->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        char ch = board[r][c];

        // Không có nhánh tương ứng
        if (ch == '#' || node->child[ch - 'a'] == nullptr) {
            return;
        }

        Node* next = node->child[ch - 'a'];

        // Tìm thấy một từ
        if (!next->word.empty()) {
            ans.push_back(next->word);

            // Tránh thêm cùng một từ nhiều lần
            next->word = "";
        }

        // Đánh dấu ô hiện tại đã sử dụng
        board[r][c] = '#';

        dfs(board, r - 1, c, next);
        dfs(board, r + 1, c, next);
        dfs(board, r, c - 1, next);
        dfs(board, r, c + 1, next);

        // Khôi phục ô
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        root = new Node();

        // Xây Trie từ tất cả words
        for (string& word : words) {
            insert(word);
        }

        // DFS từ mọi ô
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};