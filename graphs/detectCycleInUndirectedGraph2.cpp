class Graph {

public:
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        //parent ko yaad rakho and jab naya koi mile check karo ki ye visited hai ya nai
        //agar visited nai hai visit kar lo and agar visited hai to check karo ki tumhara parent ye hai kya
        //agar nai to cycle hai.
        //doesn't matter kaise traverse kar rahe ho . same hi hai
        queue<pair<int, int>> q;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                q.push({i, -1});
                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for (int i = 0; i < adj[node].size(); i++) {
                        int neigh = adj[node][i];
                        if (vis[neigh] == 0 && neigh) {
                            vis[neigh] = 1;
                            q.push({neigh, node});
                        }
                        else if (neigh != parent) {
                            return true;
                        }
                    }
                }

            }
        }
        return false;
    }
};