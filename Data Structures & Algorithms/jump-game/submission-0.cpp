class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Không thể đi tới vị trí i
            if (i > farthest)
                return false;

            // Cập nhật vị trí xa nhất có thể tới
            farthest = max(farthest, i + nums[i]);

            // Đã tới được cuối
            if (farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};