class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord không tồn tại -> không thể biến đổi
        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int step = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == endWord)
                    return step;

                // Thử thay từng ký tự
                for (int i = 0; i < cur.size(); i++) {
                    char original = cur[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        cur[i] = c;

                        // Tìm từ mới trong wordList
                        if (words.count(cur)) {
                            q.push(cur);

                            // Đánh dấu đã sử dụng
                            words.erase(cur);
                        }
                    }

                    cur[i] = original;
                }
            }

            step++;
        }

        return 0;
    }
};
