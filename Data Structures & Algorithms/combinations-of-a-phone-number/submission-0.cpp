class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        // Nếu digits rỗng
        if (digits.empty()) {
            return result;
        }

        vector<string> phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string path;

        backtrack(digits, 0, phone, path, result);

        return result;
    }

private:
    void backtrack(
        string& digits,
        int index,
        vector<string>& phone,
        string& path,
        vector<string>& result
    ) {
        // Đã chọn ký tự cho tất cả chữ số
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        // Lấy các ký tự tương ứng với digits[index]
        string letters = phone[digits[index] - '0'];

        for (char c : letters) {
            // Chọn
            path.push_back(c);

            // Sang chữ số tiếp theo
            backtrack(
                digits,
                index + 1,
                phone,
                path,
                result
            );

            // Quay lui
            path.pop_back();
        }
    }
};