class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // 1 chữ số: 1 -> 9
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }

            // 2 chữ số: 10 -> 26
            if (i >= 2) {
                int num = (s[i - 2] - '0') * 10
                        + (s[i - 1] - '0');

                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};