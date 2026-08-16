class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // graph[u] chứa các chữ cái đứng sau u
        vector<vector<int>> graph(26);

        // indegree[i] = số chữ cái đứng trước i
        vector<int> indegree(26, 0);

        // Chỉ những chữ cái thực sự xuất hiện mới được tính
        vector<bool> exists(26, false);

        for (string& word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        // So sánh từng cặp từ liên tiếp
        for (int i = 0; i + 1 < words.size(); i++) {
            string& a = words[i];
            string& b = words[i + 1];

            int len = min(a.size(), b.size());
            int j = 0;

            // Tìm ký tự đầu tiên khác nhau
            while (j < len && a[j] == b[j]) {
                j++;
            }

            // Trường hợp:
            // a = "abc"
            // b = "ab"
            // => không hợp lệ
            if (j == len && a.size() > b.size()) {
                return "";
            }

            // Có ký tự khác nhau
            if (j < len) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                graph[u].push_back(v);
                indegree[v]++;
            }
        }

        queue<int> q;

        // Các chữ cái không có chữ nào đứng trước
        for (int i = 0; i < 26; i++) {
            if (exists[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans += char('a' + u);

            for (int v : graph[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Nếu không lấy đủ tất cả chữ cái
        // => đồ thị có chu trình
        int totalChars = 0;

        for (bool x : exists) {
            if (x)
                totalChars++;
        }

        if (ans.size() != totalChars) {
            return "";
        }

        return ans;
    }
};