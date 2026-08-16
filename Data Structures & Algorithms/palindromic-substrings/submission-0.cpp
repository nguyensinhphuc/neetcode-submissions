class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Palindrome có độ dài lẻ
            expand(i, i);

            // Palindrome có độ dài chẵn
            expand(i, i + 1);
        }

        return ans;
    }
};