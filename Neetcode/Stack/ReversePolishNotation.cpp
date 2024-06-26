#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Solution {
    public:
        int evalRPN(vector<string>& tokens) {

            unordered_map<string, int> map;
            map["+"] = 0;
            map["-"] = 1;
            map["*"] = 2;
            map["/"] = 3;

            stack<int> s;
            for (int i = 0; i < tokens.size(); i++) {
                if (map.find(tokens[i]) != map.end()) {
                    int val = map[tokens[i]];
                    int num1 = s.top();
                    s.pop();
                    int num2 = s.top();
                    s.pop();
                    switch (val) {
                    case 0: s.push(num2 + num1); break;
                    case 1: s.push(num2 - num1); break;
                    case 2: s.push(num2 * num1); break;
                    case 3: s.push(num2 / num1); break;
                    }
                } else {
                    s.push(stoi(tokens[i]));
                }
            }
            return s.top();
        }
    };
};

int main() {

    int n;
    cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++)
        cin >> tokens[i];
    Solution obj;
    int ans;
    ans = obj.evalRPN(tokens);
    cout << ans << endl;
    return 0;


}