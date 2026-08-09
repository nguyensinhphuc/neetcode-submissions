class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for (int x : nums)
            cnt[x]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &[x, f] : cnt)
            bucket[f].push_back(x);

        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int x : bucket[i]) {
                ans.push_back(x);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};