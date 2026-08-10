class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // Nếu ký tự đã xuất hiện trong cửa sổ hiện tại
            if (last[c] >= left) {
                left = last[c] + 1;
            }

            last[c] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};