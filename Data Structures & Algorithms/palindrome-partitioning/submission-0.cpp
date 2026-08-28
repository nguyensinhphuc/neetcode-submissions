class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;

        backtrack(s, 0, path, result);

        return result;
    }

private:
    void backtrack(
        string& s,
        int start,
        vector<string>& path,
        vector<vector<string>>& result
    ) {
        // Đã xử lý hết chuỗi
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        // Thử mọi vị trí kết thúc
        for (int end = start; end < s.size(); end++) {

            // Nếu s[start...end] không phải palindrome
            if (!isPalindrome(s, start, end)) {
                continue;
            }

            // Chọn chuỗi con palindrome
            path.push_back(s.substr(start, end - start + 1));

            // Xử lý phần còn lại
            backtrack(s, end + 1, path, result);

            // Quay lui
            path.pop_back();
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
