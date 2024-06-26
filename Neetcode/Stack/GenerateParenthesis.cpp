class Solution {
public:
    void dfs(int openCount, int closedCount, string temp, vector<string>& ans, int n) {
        if (closedCount == openCount && openCount == n) {
            ans.push_back(temp);
            temp.clear();
            return;
        }
        cout << temp << endl;
        if (openCount < n)
            dfs(openCount + 1, closedCount, temp + "(", ans, n);
        if (closedCount < openCount)
            dfs(openCount, closedCount + 1, temp + ")", ans, n);

    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        dfs(0, 0, "", ans, n);
        return ans;

    }
};