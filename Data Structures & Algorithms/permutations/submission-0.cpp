class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtrack(nums, path, used, result);

        return result;
    }

private:
    void backtrack(
        vector<int>& nums,
        vector<int>& path,
        vector<bool>& used,
        vector<vector<int>>& result
    ) {
        // Đã tạo đủ một hoán vị
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // Thử từng phần tử
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            // Chọn
            path.push_back(nums[i]);
            used[i] = true;

            // Đệ quy
            backtrack(nums, path, used, result);

            // Quay lui
            path.pop_back();
            used[i] = false;
        }
    }
};