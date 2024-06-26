#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:

	int predicate(vector<int>& nums, int value) {
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= value)
				count++;
		}
		return count;
	}
	int findDuplicate(vector<int>& nums) {

		int low = 1, high = nums.size() - 1, ans = 0;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (predicate(nums, mid) > mid) {
				ans = mid;
				high = mid - 1;
			} else
				low = mid + 1;
		}
		return ans;
	}
};

int main() {

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution obj;
	int ans;
	ans = obj.findDuplicate(nums);
	cout << ans << endl;
	return 0;


}