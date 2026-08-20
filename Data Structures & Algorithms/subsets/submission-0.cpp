class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(int index, vector<int>& nums) {
        // Mỗi trạng thái hiện tại đều là một tập con
        ans.push_back(cur);

        for (int i = index; i < nums.size(); i++) {
            // Chọn nums[i]
            cur.push_back(nums[i]);

            backtrack(i + 1, nums);

            // Bỏ chọn nums[i]
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};