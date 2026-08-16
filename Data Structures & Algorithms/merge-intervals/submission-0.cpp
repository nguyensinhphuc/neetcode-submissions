class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sắp xếp theo điểm bắt đầu
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto& interval : intervals) {
            // Chưa có interval nào hoặc không chồng lấn
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                // Chồng lấn -> gộp lại
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};