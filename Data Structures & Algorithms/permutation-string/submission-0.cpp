class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (char c : s1)
            cnt1[c - 'a']++;

        int len = s1.size();

        // Cửa sổ đầu tiên
        for (int i = 0; i < len; i++)
            cnt2[s2[i] - 'a']++;

        if (cnt1 == cnt2)
            return true;

        // Trượt cửa sổ
        for (int i = len; i < s2.size(); i++) {
            cnt2[s2[i] - 'a']++;           // thêm ký tự mới
            cnt2[s2[i - len] - 'a']--;     // bỏ ký tự cũ

            if (cnt1 == cnt2)
                return true;
        }

        return false;
    }
};