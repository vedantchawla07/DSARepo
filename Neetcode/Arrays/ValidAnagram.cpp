class Solution {
public:
    bool isAnagram(string s, string t) {
        //https://leetcode.com/problems/valid-anagram/
        int slen = s.size();
        int tlen = t.size();
        if (slen != tlen)   return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (int i = 0; i < slen; i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }
        for (auto it1 = map1.begin(); it1 != map1.end(); it1++) {
            if (it1->second != map2[it1->first])
                return false;
        }
        return true;
    }
};