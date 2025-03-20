//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    int n;
    void bfs(vector<vector<int>> &adj, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        
        while(!q.empty())
        {
            int u= q.front();
            q.pop();
            
            for(int v = 0; v < n; v++)
            {
                if(adj[u][v] == 1 && !visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V, false);
        
        int count = 0; 
        n = adj.size();
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i]){
                bfs(adj, i, visited);
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends