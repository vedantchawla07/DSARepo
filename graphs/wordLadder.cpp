#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb emplace_back
int traversal(map<string, int> map, string beginWord, vector<string>& wordList, vector<string> adj[], int ladderLength, string endWord) {
	auto it = find(wordList.begin(), wordList.end(), beginWord);
	int index = it - wordList.begin();
	for (int i = 0; i < adj[index].size(); i++) {
		string adjWord = adj[index][i];
		if (adjWord == endWord) {
			ladderLength++;
			return ladderLength;
		}
		else {
			if (map[adjWord] == 0) {
				map[adjWord] = 1;
				//cout << adjWord << endl;
				int ans = traversal(map, adjWord, wordList, adj, ladderLength + 1, endWord);
				if (ans != 0)
					return ans;
			}

		}

	}
	return 0;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	map<string, int> map;
	map[beginWord] = 0;
	for (int i = 0; i < wordList.size(); i++) {
		map[wordList[i]] = 0;
	}
	vector<string> adj[wordList.size() + 1];
	wordList.push_back(beginWord);
	for (int k = 0; k < wordList.size(); k++) {
		string word1 = wordList[k];
		cout << word1 << endl;
		vector<string> temp;
		for (int i = 0; i < word1.size(); i++) {
			string word = word1;
			char x = word[i];
			for (int j = 0; j < 26; j++) {

				char replace = (char)('a' + j);
				string replace1 = "";
				replace1 = replace;
				word[]
				if (map.find(word) != map.end() && word != word1) {
					temp.push_back(word);
				}
			}

		}
		if (temp.size() > 0)
			adj[k] = temp;

	}

	map[beginWord] = 1;
	return traversal(map, beginWord , wordList, adj, 0, endWord);
}

int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		string beginWord , endWord ;
		int n;

		cin >> beginWord >> endWord ;
		cin >> n;
		vector<string> wordList;
		string temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			wordList.push_back(temp);
		}
		cout << ladderLength(beginWord, endWord, wordList) << endl;


	}
	return 0;
}