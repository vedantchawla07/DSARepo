class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int low = 0, high = n - 1, ans = 0;
        while (low < high) {
            int value = min(height[low], height[high]) * (high - low);
            //cout << value << " " << height[low]<< " " << height[high]<< endl;
            if (height[low] < height[high]) low++;
            else high--;
            ans = max(ans, value);
        }
        return ans;

    }
};