class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1)
            return s;

        int bestL = 0;
        int bestLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len > bestLen) {
                    bestLen = len;
                    bestL = l;
                }

                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Palindrome độ dài lẻ
            expand(i, i);

            // Palindrome độ dài chẵn
            expand(i, i + 1);
        }

        return s.substr(bestL, bestLen);
    }
};