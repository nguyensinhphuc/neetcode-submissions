class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Luôn binary search trên mảng ngắn hơn
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            // Số phần tử lấy từ nums1 sang bên trái
            int cut1 = left + (right - left) / 2;

            // Số phần tử lấy từ nums2 sang bên trái
            int cut2 = (m + n + 1) / 2 - cut1;

            // Phần tử lớn nhất bên trái nums1
            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];

            // Phần tử nhỏ nhất bên phải nums1
            int R1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            // Phần tử lớn nhất bên trái nums2
            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // Phần tử nhỏ nhất bên phải nums2
            int R2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Đã chia đúng
            if (L1 <= R2 && L2 <= R1) {

                // Tổng số phần tử lẻ
                if ((m + n) % 2 == 1) {
                    return max(L1, L2);
                }

                // Tổng số phần tử chẵn
                int leftMax = max(L1, L2);
                int rightMin = min(R1, R2);

                return (leftMax + rightMin) / 2.0;
            }

            // Lấy quá nhiều phần tử từ nums1
            else if (L1 > R2) {
                right = cut1 - 1;
            }

            // Lấy quá ít phần tử từ nums1
            else {
                left = cut1 + 1;
            }
        }

        return 0.0;
    }
};