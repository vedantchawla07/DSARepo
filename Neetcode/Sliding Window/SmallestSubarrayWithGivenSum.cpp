#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calledFunction(vector<int>& nums, int desiredSum) {


		int windowStart = 0, n = nums.size(), ans = n, currentSum = 0;
		for (int windowEnd = 0; windowEnd < n; windowEnd++) {
			currentSum += nums[windowEnd];
			while (currentSum >= desiredSum) {
				ans = min(ans, windowEnd - windowStart + 1);
				currentSum -= nums[windowStart];
				windowStart++;
			}
		}

		return ans;
	}
};

int main() {

	int n, sum;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> sum;
	Solution obj;
	int ans;
	ans = obj.calledFunction(nums, sum);
	cout << ans << endl;
	return 0;


}