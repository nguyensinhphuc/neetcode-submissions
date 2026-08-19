class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Tổng lẻ thì không thể chia thành 2 phần bằng nhau
        if (total % 2 != 0)
            return false;

        int target = total / 2;

        // dp[s] = có thể tạo ra tổng s hay không
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            // Đi từ phải sang trái để mỗi phần tử
            // chỉ được sử dụng đúng một lần
            for (int s = target; s >= x; s--) {
                dp[s] = dp[s] || dp[s - x];
            }
        }

        return dp[target];
    }
};