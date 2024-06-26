#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calledFunction(vector<int>& nums, int k) {

		int windowLength = 0, ans = 0, n = nums.size(), windowSum = 0;
		for (int i = 0; i < n; i++) {
			windowSum += nums[i];
			if (i >= k - 1) {
				ans = max(ans, windowSum);
				windowSum -= nums[i - (k - 1)];
			}
		}

		return ans;
	}
};

int main() {

	int n, k;
	cin >> n ;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> k;
	Solution obj;
	int ans;
	ans = obj.calledFunction(nums, k);
	cout << ans << endl;
	return 0;


}