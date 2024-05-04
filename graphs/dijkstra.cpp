//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    /*vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //USING PRIORITY QUEUE
        priority_queue<pair<int,int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i = 0; i < V; i++){
            dist[i] = INT_MAX;
        }
        pq.push({S,0});
        dist[S] = 0;
        while(!pq.empty()){
            int node = pq.top().first;
            int myWeight = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int surrNode = it[0];
                int newDistance = myWeight + edgeWeight;
                if(newDistance  < dist[surrNode]){
                    dist[surrNode] = newDistance;
                    pq.push({surrNode, newDistance});
                }
            }
        }
        return dist;
    }*/
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //using set


        // all will have T.C of ElogV.
        set<pair<int, int>> s;
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[S] = 0;
        s.insert({0, S});
        while (!s.empty()) {
            auto it = *(s.begin());
            int node = it.second;
            int weight = it.first;
            s.erase(it);
            for (auto i : adj[node]) {
                int edgeWeight = i[1];
                int surrNode = i[0];
                if (weight + edgeWeight < dist[surrNode]) {
                    if (dist[surrNode] != INT_MAX) {
                        s.erase({dist[surrNode], surrNode});
                    }
                    dist[surrNode] = weight + edgeWeight;
                    s.insert({dist[surrNode], surrNode});
                }
            }

        }
        return dist;
    }
    /*
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        //USING NORMAL QUEUE
        priority_queue<pair<int,int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
        queue<pair<int,int>> q;
        vector<int> dist(V);
        for(int i = 0; i < V; i++){
            dist[i] = INT_MAX;
        }
        pq.push({S,0});
        dist[S] = 0;
        q.push({S,0});
        while(!q.empty()){
            int node = q.front().first;
            int myWeight = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int surrNode = it[0];
                int newDistance = myWeight + edgeWeight;
                if(newDistance  < dist[surrNode]){
                    dist[surrNode] = newDistance;
                    q.push({surrNode, newDistance});
                }
            }
        }
        return dist;
    }
    */
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}


// } Driver Code Ends