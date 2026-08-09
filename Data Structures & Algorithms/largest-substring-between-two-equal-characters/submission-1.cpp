class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int ans = -1;

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] == -1) {
                // Lần đầu gặp ký tự này
                first[x] = i;
            } else {
                // Đã gặp trước đó
                ans = max(ans, i - first[x] - 1);
            }
        }

        return ans;
    }
};