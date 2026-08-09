class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        for (char c : t)
            cnt[c - 'a']--;

        for (int x : cnt)
            if (x != 0)
                return false;

        return true;
    }
};