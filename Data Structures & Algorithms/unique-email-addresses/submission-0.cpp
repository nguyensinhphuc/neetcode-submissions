class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string email : emails) {
            string local = "";
            string domain = "";

            int at = email.find('@');

            // Xử lý local
            for (int i = 0; i < at; i++) {
                if (email[i] == '+') {
                    break;
                }

                if (email[i] != '.') {
                    local += email[i];
                }
            }

            // Lấy domain
            domain = email.substr(at + 1);

            st.insert(local + "@" + domain);
        }

        return st.size();
    }
};