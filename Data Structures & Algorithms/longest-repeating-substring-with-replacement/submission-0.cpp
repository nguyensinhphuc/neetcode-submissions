class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - 'A']++;

            // Số lần xuất hiện nhiều nhất trong cửa sổ
            maxFreq = max(maxFreq, cnt[s[right] - 'A']);

            // Số ký tự cần thay thế
            int need = (right - left + 1) - maxFreq;

            while (need > k) {
                cnt[s[left] - 'A']--;
                left++;

                need = (right - left + 1) - maxFreq;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};