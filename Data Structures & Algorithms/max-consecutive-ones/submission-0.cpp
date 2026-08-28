class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int ans = 0;

        for (int x : nums) {
            if (x == 1) {
                current++;
                ans = max(ans, current);
            } else {
                current = 0;
            }
        }

        return ans;
    }
};