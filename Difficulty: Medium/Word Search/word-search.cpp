class Solution {
  public:
    bool solve(vector<vector<char>>& mat, string& word, int i, int j, int idx, vector<vector<bool>> &vis)
    {
        if(idx == word.length()) return true;
        
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[idx] || vis[i][j])
        return false;
        
        vis[i][j] = true;
        
        if(solve(mat, word, i - 1, j, idx + 1, vis) || solve(mat, word, i + 1, j, idx + 1, vis) ||
        solve(mat, word, i, j - 1, idx + 1, vis) || solve(mat, word, i, j + 1, idx + 1, vis) ) return true;
        
        vis[i][j] = false;
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == word[0])
                {
                    if(solve(mat, word, i, j, 0, vis)) return true;
                }
            }
        }
        return false;
    }
};