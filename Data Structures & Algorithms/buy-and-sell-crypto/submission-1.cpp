class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Giá mua thấp nhất
            minPrice = min(minPrice, price);

            // Lợi nhuận nếu bán hôm nay
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};