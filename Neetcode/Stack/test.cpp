#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calledFunction(vector<int>& nums) {

		sort(nums.begin(), nums.end(), [](int a, int b)
		{
			return a > b;
		});
		for (auto it : nums)
			cout << it << " ";
		cout << endl;
		return 0;
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
	ans = obj.calledFunction(nums);
	cout << ans << endl;
	return 0;


}