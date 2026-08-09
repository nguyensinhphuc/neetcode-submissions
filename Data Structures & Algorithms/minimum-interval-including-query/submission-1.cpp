class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        // Sắp xếp interval theo left
        sort(intervals.begin(), intervals.end());

        // Lưu query cùng vị trí ban đầu
        vector<pair<int, int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        // Sắp xếp query tăng dần
        sort(qs.begin(), qs.end());

        // {độ dài, right}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int j = 0;

        for (auto [q, index] : qs) {

            // Thêm tất cả interval có left <= q
            while (j < intervals.size() &&
                   intervals[j][0] <= q) {

                int left = intervals[j][0];
                int right = intervals[j][1];

                int len = right - left + 1;

                pq.push({len, right});

                j++;
            }

            // Xóa những interval đã kết thúc trước q
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // Interval nhỏ nhất đang chứa q
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};