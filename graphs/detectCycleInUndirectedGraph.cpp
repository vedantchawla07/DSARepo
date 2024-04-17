//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {


        //store the parent of the currNode. Basically when you are traversing, store the node in the queue along with its parent node.
        //So that when you actually encounter a cycle, you will be like, "Oh this is already visited but wait, this is not my parent. I am not coming from here. Who visited this node. Must be a cycle"
        //For the rest of the times, when you actually try visiting the parent node and see it is visited, you check whether it is my parent or not
        //yes it is your parent, then it means it should be visited only.
        //normal dfs or bfs traversal works.
        //if it is not visited, visit it and mark current node as parent node.
        // if it is visited, check if parent node is same as the visited neighbour, if yes, no cycle if no cycle




        //For DFS, how do you plan on carrying the parent node.In the stack itself?
        //if visited and neighbour not equal to parent node, cycle. Simple.
        //if not visited, visit but also check what it is returning. That is also important
    }
};

//{ Driver Code Starts.
int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t-- > 0) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends