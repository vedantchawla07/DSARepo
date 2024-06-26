class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> posSpeed(n);
        vector<double> time(n);
        for (int i = 0 ; i < n; i++) {
            posSpeed[i].first = position[i];
            posSpeed[i].second = speed[i];
        }
        sort(posSpeed.begin(), posSpeed.end(), [](const auto a, const auto b) {
            return a.first > b.first; //greater hai matlab no swapping
        });

        double currMax = 0;
        int ans = 0;
        for (auto it : posSpeed) {
            double time = (double) (target - it.first) / it.second;
            if (time > currMax) {
                currMax = time;
                ans++;
            }
        }
        return ans;
    }
};