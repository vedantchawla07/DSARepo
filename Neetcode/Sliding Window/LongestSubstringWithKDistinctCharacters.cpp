#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calledFunction(string str, int k) {

		int n = str.size(), windowStart = 0, ans = 0;
		unordered_map<char, int> map;
		cout << n << endl;
		cout << str << endl;
		for (int windowEnd = 0; windowEnd < n; windowEnd++) {
			map[str[windowEnd]]++;
			while (map.size() > k) {
				if (map[str[windowStart]] > 0)
					map[str[windowStart]]--;
				if (map[str[windowStart]] == 0)
					map.erase(str[windowStart]);
				windowStart++;
			}
			ans = max(ans, windowEnd - windowStart + 1);
			//cout << windowEnd << endl;
		}
		return ans;
	}
};

int main() {

	int k;
	string str;
	cin >> str >> k;
	Solution obj;
	int ans;
	ans = obj.calledFunction(str, k);
	cout << ans << endl;
	return 0;


}