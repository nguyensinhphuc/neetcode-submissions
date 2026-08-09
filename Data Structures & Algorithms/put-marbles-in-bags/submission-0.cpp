class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<long long> a;

        for (int i = 0; i < n - 1; i++)
            a.push_back(1LL * weights[i] + weights[i + 1]);

        sort(a.begin(), a.end());

        long long ans = 0;

        for (int i = 0; i < k - 1; i++)
            ans += a[n - 2 - i] - a[i];

        return ans;
    }
};