//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    //so the main logic is that of comparing the two adjacent strings. The first character where they differ is where I get my first dependency that this comes before that.
    //Hence I first construct a graph containing the dependencies and then apply topo sort to it.
    string findOrder(string dict[], int N, int K) {
        vector<int> inDegree(26, 0);
        vector<int> adj[26];
        vector<int> topo;
        vector<int> vis(26, 0);
        queue<int> q;
        string ans;
        for (int i = 0 ; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int j = 0;
            int l1 = word1.size();
            int l2 = word2.size();
            while (j < l1 && j < l2) {
                if (word1[j] != word2[j]) {
                    int node = word1[j] - 97;
                    int surrNode = word2[j] - 97;
                    vis[node] = 1;
                    vis[surrNode] = 1;
                    adj[node].push_back(surrNode); //Note that this might result in duplicacy. Which means that a node can have the same adjacent node twice. Why doesn't it affect the execution of the program? Because later you calculate its inDegree twice and when you visit after some time using q and traversal, you will traverse twice and decrement twice and then add it to the q.(Line 54)
                    break;
                }
                j++;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] == 0 && vis[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (topo.size() == 0) {
            //what is the logic behind this? Take an example of [aaaa, aaaaa, aaaaaa] and the value of k = 1. The answer is a.
            string word = dict[0];
            word.assign(1, word[0]);
            return word;
        }
        for (int i = 0; i < K; i++) {
            ans += topo[i] + 97;
        }

        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if (f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends