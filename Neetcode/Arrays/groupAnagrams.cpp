#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        if (strs.size() == 0) return {{}};
        if (strs.size() == 1) return {strs};
        vector<vector<string>> ans;
        for (int i = 0 ; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word. end());
            map[word].push_back(strs[i]);
        }
        for (auto it : map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {

    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    Solution obj;
    vector<vector<string>> ans;
    ans = obj.groupAnagrams(strs);
    for (auto it : ans) {
        for (auto i : it) {
            cout << i << ",";
        }
        cout << endl;
    }
    return 0;


}