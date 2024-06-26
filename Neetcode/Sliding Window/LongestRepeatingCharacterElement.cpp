#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	char mostFrequentElement(unordered_map<char, int>& map) {

		int value = 0;
		char ans;
		for (auto it : map) {
			if (value < it.second) {
				value = it.second;
				ans = it.first;
			}
		}
		return ans;

	}
	int characterReplacement(string s, int k) {

		//I need count of the most frequent character. When I delete it. I will find the windowlength. If it is less. I will proceed. Otherwise, I will keep on deleting the windowStart. But why do you need the count of the most frequent character. Because that will determine how many changes I have made.
		//https://www.youtube.com/watch?v=MK-NZ4hN7rs

		int windowStart = 0, ans = 0, n = s.size();
		unordered_map<char, int> map;
		for (int windowEnd = 0; windowEnd < n; windowEnd++) {
			map[s[windowEnd]]++;
			// I need to check whether map.size() -  map[mostFreqCharacter] > k
			while ((windowEnd - windowStart + 1) - map[mostFrequentElement(map)] > k) {
				map[s[windowStart]]--;
				if (map[s[windowStart]] == 0)
					map.erase(s[windowStart]);
				windowStart++;
			}
			ans = max(ans, windowEnd - windowStart + 1);
		}
		return ans;
	}
};
int main() {

	string s;
	int k;
	cin >> s >> k;

	Solution obj;
	int ans;
	ans = obj.characterReplacement(s, k);
	cout << ans << endl;
	return 0;


}