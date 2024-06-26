#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> calledFunction(vector<int>& nums) {

		stack<int> st;
		int n = nums.size();
		vector<int> ans(n);
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && st.top() <= nums[i])
				st.pop();
			ans[i] = (st.empty() ? -1 : st.top());

			st.push(nums[i]);
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
	vector<int> ans;
	ans = obj.calledFunction(nums);
	for (auto it : ans)
		cout << it << " ";
	return 0;


}