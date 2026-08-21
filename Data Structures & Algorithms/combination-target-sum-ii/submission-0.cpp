class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Bỏ duplicate ở cùng một level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Đã sort nên có thể dừng
            if (candidates[i] > target)
                break;

            cur.push_back(candidates[i]);

            // i + 1: mỗi phần tử chỉ dùng 1 lần
            backtrack(candidates, i + 1, target - candidates[i]);

            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return ans;
    }
};