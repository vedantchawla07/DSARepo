//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int bfs(string startWord, string targetWord, set<string> words) {
        queue<string> q;
        q.push(startWord);
        int ans = 1;
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l ; i++) {
                string currWord = q.front();
                q.pop();
                words.erase(currWord);
                for (int j = 0; j < currWord.size(); j++) {
                    for (int k = 0; k < 26; k++) {
                        char currChar = k + 97;
                        string newWord = currWord;
                        newWord[j] = currChar;
                        auto it = words.find(newWord);
                        if (it != words.end() && newWord != currWord) {
                            q.push(newWord);
                            if (newWord == targetWord) {
                                return ans + 1;
                            }
                        }
                    }
                }
            }
            ans = ans + 1;
        }
        return 0;
    }
    bool dfs(string& currWord, string& endWord, set<string>& words, int depth, vector<string>& path, vector<vector<string>>& ans, unordered_map<string, int>& map) {

        bool flag = false;
        if (depth == 0) {
            if (currWord == endWord) {
                path.push_back(currWord);
                ans.push_back(path);
                path.pop_back();
                return true;
            } else
                return false;
        }
        path.push_back(currWord);
        map[currWord] = 2;
        for (int i = 0; i < currWord.size(); i++) {
            for (int j = 0; j < 26; j++) {
                char currLetter = j + 97;
                string newWord = currWord;
                newWord[i] = currLetter;
                if (words.find(newWord) != words.end() && map[newWord] == 1) {
                    if (dfs(newWord, endWord, words, depth - 1, path, ans, map) == true) {
                        flag = true;
                    }
                }
            }
        }
        path.pop_back();
        map[currWord] = 1;
        if (flag == true)
            return true;
        return false;

    }
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> path;
        vector<vector<string>> ans;
        set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, int> map;

        for (int i = 0; i < wordList.size(); i++) {
            map[wordList[i]]++;
        }

        int depth = bfs(beginWord, endWord, words);
        if (depth == 0) {
            return {};
        }
        else {
            bool isTrue = dfs(beginWord, endWord, words, depth - 1, path, ans, map);
            return ans;
        }

    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main() {


    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string>wordList(n);
        for (int i = 0; i < n; i++)cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends