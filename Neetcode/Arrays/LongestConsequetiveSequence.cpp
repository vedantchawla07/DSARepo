#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, ans = 0;
        if (n == 1) return 1;
        while (i < n - 1) {
            int count = 1;
            while (abs(nums[i] - nums[i + 1]) == 1 && i < n - 1) {
                count++;
                i++;
            }
            ans = max(ans, count);
            i++;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << *max_element(nums.begin(), nums.begin() + 5) << endl;
    Solution obj;
    cout << obj.longestConsecutive(nums) << endl;

    return 0;
}