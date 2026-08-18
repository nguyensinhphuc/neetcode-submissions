class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int cur = cost[i] + min(prev1, prev2);

            prev2 = prev1;
            prev1 = cur;
        }

        // Có thể đi từ n-1 lên top
        // hoặc từ n-2 lên top
        return min(prev1, prev2);
    }
};