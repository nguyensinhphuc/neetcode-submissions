class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Nửa bên trái được sắp xếp
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    // Target nằm trong nửa trái
                    right = mid - 1;
                } else {
                    // Target nằm ở nửa phải
                    left = mid + 1;
                }
            }
            // Nửa bên phải được sắp xếp
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    // Target nằm trong nửa phải
                    left = mid + 1;
                } else {
                    // Target nằm ở nửa trái
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};