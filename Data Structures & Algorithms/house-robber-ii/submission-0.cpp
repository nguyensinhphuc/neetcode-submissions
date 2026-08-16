class Solution {
public:
    int robRange(vector<int>& nums, int l, int r) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = l; i <= r; i++) {
            int cur = max(prev1, prev2 + nums[i]);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Chỉ có 1 nhà
        if (n == 1)
            return nums[0];

        // Không cướp nhà cuối
        int case1 = robRange(nums, 0, n - 2);

        // Không cướp nhà đầu
        int case2 = robRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};