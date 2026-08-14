class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(vector<int>& nums, int target, int start) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Vì nums đã được sắp xếp
            if (nums[i] > target) {
                break;
            }

            cur.push_back(nums[i]);

            // i chứ không phải i + 1
            // vì được phép dùng nums[i] nhiều lần
            backtrack(nums, target - nums[i], i);

            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        backtrack(nums, target, 0);

        return ans;
    }
};