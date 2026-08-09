class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0;
        long long right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long coins = mid * (mid + 1) / 2;

            if (coins <= n) {
                // Có thể xây được mid hàng
                left = mid + 1;
            } else {
                // mid hàng cần quá nhiều xu
                right = mid - 1;
            }
        }

        return right;
    }
};