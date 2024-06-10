#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

	string encode(vector<string>& strs) {
		string ans = "";
		for (int i = 0; i < strs.size(); i++) {
			string str = strs[i];
			int len = str.length();
			//cout << len << endl;
			ans =  ans + to_string(len) + "#" + str;
		}

		return ans;
	}

	vector<string> decode(string s) {

		vector<string> ans;
		int i = 0, j = 0;
		string str = "";
		while (i < s.size()) {
			int j = i;
			while (s[j] != '#') {
				j++;
			}

			string x = s.substr(i, j - i);
			cout << x << endl;
			int l = stoi(x);

			i = j + 1;
			j = j + 1;
			for (; j < i + l; j++) {
				str = str + s[j];
			}
			ans.push_back(str);
			str = "";
			i = j;
			cout << i << endl;
		}
		return ans;
	}
};

int main()
{


	int n, k;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}
	Solution obj;
	string ans = obj.encode(strs);
	vector<string> ansString;
	cout << ans << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << i ;
	cout << endl;

	ansString = obj.decode(ans);
	for (auto it : ansString) {
		cout << it << " ";
	}
	return 0;
}