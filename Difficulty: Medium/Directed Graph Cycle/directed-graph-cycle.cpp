//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
     vector<int> InDeg(V, 0);
    
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < adj[i].size(); j++) 
        InDeg[adj[i][j]]++;
    }
    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(!InDeg[i]) q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if(!InDeg[adj[node][j]]) q.push(adj[node][j]);
        }
    }
    int count = ans.size();
    return count != V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends