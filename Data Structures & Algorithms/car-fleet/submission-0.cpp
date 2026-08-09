class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Gần đích -> xa đích
        sort(cars.begin(), cars.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        int ans = 0;
        double lastTime = 0;

        for (auto &[pos, time] : cars) {
            if (time > lastTime) {
                ans++;
                lastTime = time;
            }
        }

        return ans;
    }
};