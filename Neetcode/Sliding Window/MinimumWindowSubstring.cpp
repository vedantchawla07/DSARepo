#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isEqual(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {

        for (auto it : map2) {
            if (it.second < map1[it.first])
                return false;
        }
        return true;
    }
    string minWindow1(string s2, string s1) {



        //s1 chota hai
        //s2 bada hai
        int m = s1.size();
        int n = s2.size();
        if (n < m) return "";
        int windowStart = 0;
        int ansSize = INT_MAX;
        pair<int, int> ans;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (int i = 0; i < m; i++)
            map1[s1[i]]++;
        for (int windowEnd = 0; windowEnd < n; windowEnd++) {
            if (map1.find(s2[windowEnd]) != map1.end())
                map2[s2[windowEnd]]++;
            while (map1.size() == map2.size() && isEqual(map1, map2)) {
                //cout << s2[windowStart] << ' ' << s2[windowEnd] << ' ';
                if (ansSize > windowEnd - windowStart + 1) {
                    ansSize = windowEnd - windowStart + 1;
                    ans = {windowStart, windowEnd};
                    //cout << ans << endl;
                }
                if (map2.find(s2[windowStart]) != map2.end()) { //startWindow wala character map2 me hai.
                    map2[s2[windowStart]]--;
                    if (map2[s2[windowStart]] == 0) map2.erase(s2[windowStart]);
                }
                windowStart++;
            }
        }
        if (ansSize  == INT_MAX)
            return "";
        return s2.substr(ans.first, ans.second - ans.first + 1);

    }


    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m == 0) return "";
        int ansSize = INT_MAX;
        pair<int, int> ans;
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < m; i++) {
            countT[t[i]]++;
        }
        int need = countT.size(), have = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < n; windowEnd++) {
            if (countT.find(s[windowEnd]) != countT.end()) {
                countS[s[windowEnd]]++;
                if (countS[s[windowEnd]] == countT[s[windowEnd]])
                    have++;
            }
            while (need == have) {
                if (ansSize > windowEnd - windowStart + 1) {
                    ansSize = windowEnd - windowStart + 1;
                    ans = {windowStart, windowEnd};
                }
                if (countT.find(s[windowStart]) != countT.end()) {
                    countS[s[windowStart]]--;
                    if (countS[s[windowStart]] <  countT[s[windowStart]])
                        have--;
                }
                windowStart++;
            }
        }
        if (ansSize == INT_MAX)
            return "";
        cout << ansSize << endl;
        return s.substr(ans.first, ans.second - ans.first + 1);

    }
};


int main() {

    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    string ans;
    ans = obj.minWindow(s1, s2);
    cout << ans << endl;
    return 0;


}