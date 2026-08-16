/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        if (n == 0) return 0;

        vector<int> start;
        vector<int> end;

        for (auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0;
        int j = 0;
        int rooms = 0;
        int ans = 0;

        while (i < n) {
            if (start[i] < end[j]) {
                // Có cuộc họp mới nhưng chưa có phòng trống
                rooms++;
                ans = max(ans, rooms);
                i++;
            } else {
                // Phòng đã trống, có thể dùng lại
                rooms--;
                j++;
            }
        }

        return ans;
    }
};