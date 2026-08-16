class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Xóa phần tử đã ra khỏi cửa sổ
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Xóa các phần tử nhỏ hơn nums[i]
            // vì chúng không thể trở thành maximum nữa
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Khi cửa sổ đủ k phần tử
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};