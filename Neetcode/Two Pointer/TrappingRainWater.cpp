class Solution {
public:
    /*
        int trap(vector<int>& height) {

            int n = height.size();
            int ans = 0;
            if (n <= 2) return 0;
            vector<int> pre(n);
            vector<int> suff(n);
            pre[0] = 0;
            int maxSoFar = height[0];
            suff[n - 1] = 0;
            for (int i = 1; i < n; i++) {
                pre[i] = maxSoFar;
                maxSoFar = max(maxSoFar, height[i]);
            }
            maxSoFar = height[n - 1];
            for (int i = n - 2; i >= 0 ; i--) {
                suff[i] = maxSoFar;
                maxSoFar = max(maxSoFar, height[i]);
            }
            for (int i = 1; i < n - 1; i++) {
                int currValue = height[i];
                int value = min(pre[i], suff[i]) - currValue;
                if (value > 0)
                    ans = ans + value;
            }
            return ans;
        }
    */
    int trap
};