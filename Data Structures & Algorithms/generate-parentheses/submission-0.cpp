class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;

        backtrack(n, 0, 0, path, result);

        return result;
    }

private:
    void backtrack(
        int n,
        int open,
        int close,
        string& path,
        vector<string>& result
    ) {
        // Đã sử dụng đủ 2n dấu ngoặc
        if (path.size() == 2 * n) {
            result.push_back(path);
            return;
        }

        // Thêm dấu '('
        if (open < n) {
            path.push_back('(');

            backtrack(n, open + 1, close, path, result);

            path.pop_back();
        }

        // Thêm dấu ')'
        if (close < open) {
            path.push_back(')');

            backtrack(n, open, close + 1, path, result);

            path.pop_back();
        }
    }
};