class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        sort(nums.begin(), nums.end());

        backtrack(nums, 0, path, result);

        return result;
    }

private:
    void backtrack(
        vector<int>& nums,
        int start,
        vector<int>& path,
        vector<vector<int>>& result
    ) {
        // Mỗi trạng thái hiện tại đều là một tập con
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {

            // Bỏ qua phần tử trùng ở cùng một level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Chọn nums[i]
            path.push_back(nums[i]);

            // Đi tiếp
            backtrack(nums, i + 1, path, result);

            // Quay lui
            path.pop_back();
        }
    }
};