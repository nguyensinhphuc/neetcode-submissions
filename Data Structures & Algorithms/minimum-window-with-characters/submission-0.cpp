class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        // Số lần mỗi ký tự cần xuất hiện trong t
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = t.size();

        int bestStart = 0;
        int bestLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // Nếu c còn thiếu trong t
            if (need[c] > 0) {
                count--;
            }

            need[c]--;

            // Đã chứa đủ tất cả ký tự của t
            while (count == 0) {
                int len = right - left + 1;

                if (len < bestLen) {
                    bestLen = len;
                    bestStart = left;
                }

                // Bỏ ký tự bên trái
                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (bestLen == INT_MAX)
            return "";

        return s.substr(bestStart, bestLen);
    }
};