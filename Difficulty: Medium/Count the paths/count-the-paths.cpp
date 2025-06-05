class Solution {
  public:
    int dfs(unordered_map<int, vector<int>> &adj, vector<int> &dp, int src, int dest)
    {
        if(src == dest) return 1;
        
        if(dp[src] != -1) return dp[src];
        
        int count = 0;
        
        for (int v : adj[src]) 
        {
            count += dfs(adj, dp, v, dest);
        }
        
        return dp[src] = count;
    }
    
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> dp(V, -1);
        
        return dfs(adj, dp, src, dest);
    }
};