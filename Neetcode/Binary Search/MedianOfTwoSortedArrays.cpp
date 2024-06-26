#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int n1 = nums1.size(), n2 = nums2.size(), left = (n1 + n2 + 1) / 2, n = n1 + n2;
		int low = 0, high = n1;
		if (n1 > n2)
			return findMedianSortedArrays(nums2, nums1);
		while (low <= high) {
			int mid1 = low + (high - low) / 2;
			int mid2 = left - mid1;
			cout << mid1 << ' ' << mid2 << endl;
			int l1 = (mid1 <= 0 || mid1 > n1) ? INT_MIN : nums1[mid1 - 1];
			int l2 = (mid2 <= 0 || mid2 > n2) ? INT_MIN : nums2[mid2 - 1];
			int r1 = (mid1 < 0 || mid1 >= 	n1) ? INT_MAX : nums1[mid1];
			int r2 = (mid2 < 0 || mid2 >= n2) ? INT_MAX : nums2[mid2];

			if (l1 > r2)
				high = mid1 - 1;
			else if (l2 > r1)
				low  = mid1 + 1;
			else {
				if (n % 2 == 0)
					return (max(l1, l2) + min(r1, r2)) / 2.0;
				else
					return max(l1, l2);
			}
		}
		return 0;
	}
};

int main() {

	int n1 , n2;
	cin >> n1 >> n2;
	vector<int> nums1(n1), nums2(n2);
	for (int i = 0; i < n1; i++) {
		cin >> nums1[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> nums2[i];
	}


	Solution obj;
	double ans;
	ans = obj.findMedianSortedArrays(nums1, nums2);
	cout << ans << endl;
	return 0;


}