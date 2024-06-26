//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    class DisjointSet {

    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n ; i++) {
                parent[i] = i;
            }
        }
        int findUltimateParent(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = findUltimateParent(parent[u]);
        }
        void unionByRank(int u, int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u , int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
        void print(int n) {
            cout << "Printing rank" << endl;
            for (int i = 1; i <= n; i++) {
                cout << rank[i] << " ";
            }
            cout << endl;
            cout << "Printing parent" << endl;
            for (int i = 1; i <= n; ++i)
            {
                cout << parent[i] << " ";
            }
            cout << endl;
        }

    };

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> map;
        int n = accounts.size();
        DisjointSet ds(n);
        vector<string> mailMap[n];
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (map.find(email) == map.end()) {
                    map[email] = i;
                } else {
                    ds.unionByRank(map[email], i);
                }
            }
        }
        for (auto it : map) {
            string email = it.first;
            int index = ds.parent[it.second];
            mailMap[index].push_back(email);
        }

        for (int i = 0; i < n; i++) {
            if (mailMap[i].size() > 0) {
                sort(mailMap[i].begin(), mailMap[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for (auto it : mailMap[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }

        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends



