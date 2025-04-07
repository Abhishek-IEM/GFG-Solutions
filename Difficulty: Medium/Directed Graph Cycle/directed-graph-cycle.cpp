//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis,vector<int> &currvis)
    {
        vis[node] = 1;
        currvis[node] = 1;
        
        for(int &v : adj[node])
        {
            if(vis[v] == 0)
            {
                if(dfs(v, adj, vis, currvis)) return true;
            }
            else if(currvis[v] == 1) return true;
        }
        
        currvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V, 0);
        vector<int> adj[V];
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i = 0; i < V; i++)
        {
            vector<int> currvis(V, 0);
            if(dfs(i, adj, vis, currvis)) return true;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends