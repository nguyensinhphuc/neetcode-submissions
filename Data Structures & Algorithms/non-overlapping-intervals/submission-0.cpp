class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sắp xếp theo end tăng dần
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // Bị chồng lấn
            if (intervals[i][0] < lastEnd) {
                removed++;
            }
            else {
                // Không chồng lấn -> giữ lại
                lastEnd = intervals[i][1];
            }
        }

        return removed;
    }
};