#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int low = 0, high = rows * cols - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			cout << mid << endl;
			int rowMid = mid / cols;
			int colMid = mid % cols;
			if (target == matrix[rowMid][colMid])
				return true;
			else if (target > matrix[rowMid][colMid])
				low = mid + 1;
			else high = mid - 1;
		}
		return false;
	}
};
int main() {

	int n, m, target;
	cin >> n >> m;
	vector<vector<int>> nums(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}

	cin >> target;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	Solution obj;
	int ans;
	ans = obj.searchMatrix(nums, target);
	if (ans)
		cout << "True" << endl;
	else cout << "False" << endl;
	return 0;


}