#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)  return false;

        for (int i = 0; i < n1; i++) {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        if (arr1 == arr2) return true;
        int windowStart = 0;
        for (int windowEnd = n1; windowEnd < n2; windowEnd++) {
            arr2[s2[windowEnd] - 'a']++;
            arr2[s2[windowStart] - 'a']--;
            windowStart++;
            if (arr1 == arr2)
                return true;
        }
        return false;

    }
#if 0
    bool checkInclusion(string s1, string s2) {


        int windowStart = 0, k = s1.size(), n = s2.size();
        unordered_map<char, int> map;
        for (int i = 0; i < k; i++)
            map[s1[i]]++;
        for (int windowEnd = 0; windowEnd < n; windowEnd++) {
            if (map.find(s2[windowEnd]) != map.end()) {
                map[s2[windowEnd]]--;
                if (map[s2[windowEnd]] == 0)
                    map.erase(s2[windowEnd]);
                if (map.size() == 0)
                    return true;
            } else {
                while (windowStart != windowEnd &&  map.find(s2[windowEnd]) == map.end()) {
                    map[s2[windowStart]]++;
                    windowStart++;
                }
                if (windowStart == windowEnd && map.find(s2[windowEnd]) == map.end())
                    windowStart++;
                if (map.find(s2[windowEnd]) != map.end())
                    map[s2[windowEnd]]--;
                if (map[s2[windowEnd]] == 0)
                    map.erase(s2[windowEnd]);
            }
        }
        return map.size() == 0;
    }
#endif
};

int main() {

    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    bool ans;
    ans = obj.checkInclusion(s1, s2);
    if (ans == 1)
        cout << "True" << endl;
    else cout << "False" << endl;
    return 0;


}