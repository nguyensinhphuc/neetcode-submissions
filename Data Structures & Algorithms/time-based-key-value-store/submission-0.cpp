class TimeMap {
private:
    // key -> danh sách {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) {
            return "";
        }

        auto &v = mp[key];

        int left = 0;
        int right = v.size() - 1;

        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                // Timestamp này hợp lệ.
                // Nhưng có thể còn timestamp lớn hơn cũng hợp lệ.
                ans = v[mid].second;
                left = mid + 1;
            } else {
                // Timestamp quá lớn.
                right = mid - 1;
            }
        }

        return ans;
    }
};