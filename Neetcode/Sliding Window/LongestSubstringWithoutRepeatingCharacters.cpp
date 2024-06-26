class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0;
        unordered_set<char> set;
        while (r < n) {
            if (set.find(s[r]) != set.end()) {
                set.erase(s[l++]);
            } else {
                ans = max(ans, r - l + 1);
                set.insert(s[r]);
                r++;
            }
        }
        return ans;
    }
};