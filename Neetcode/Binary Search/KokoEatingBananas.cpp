//https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int low = 1, high = *max_element(piles.begin(), piles.end());
		int ans = high;
		if (piles.size() == h) return high;
		while (low <= high) {
			int mid =  low + (high - low ) / 2;
			long long time = 0;
			//cout << mid << endl;
			for (auto bananas : piles) {
				time += ceil( (double) bananas / (double) mid );
			}
			cout << mid << " " << time << endl;
			if (time > h)
				low = mid + 1;
			else {
				ans = mid;
				high =  mid - 1;
			}
		}
		return ans;
	}
};