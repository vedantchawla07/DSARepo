class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0;
        int minSoFar = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minSoFar = min(minSoFar, prices[i]);
            ans = max(ans, prices[i] - minSoFar);
        }
        return ans;
    }
};