//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int dfs(string currWord, string targetWord, set<string>& words, int ans) {

        words.erase(currWord);
        for (int i = 0; i < currWord.size(); i++) {
            for (int j = 0; j < 26; j++) {
                char replaceCharacter = j + 97;
                string newWord = currWord;
                newWord[i] = replaceCharacter;
                if (newWord == targetWord)
                    return ans + 1 ;
                if (currWord == "soon")
                    cout << newWord << " ";
                //cout << newWord << " ";
                auto it = words.find(newWord);
                if (it != words.end()) {
                    cout << newWord << " " << ans << endl;
                    int newAns = dfs(newWord, targetWord, words, ans + 1);
                    if (newAns != -1)
                        return newAns;
                }
            }
        }
        return -1;
    }
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {

        set<string> words;
        int ans = 0;
        for (int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }
        return dfs(startWord, targetWord, words, ans);
    }
};

//{ Driver Code Starts.
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
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends