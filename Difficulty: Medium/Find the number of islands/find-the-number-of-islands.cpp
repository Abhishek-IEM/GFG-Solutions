//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
     
    bool isValid(int i, int j, int n, int m)
    {
        return i >=0 && i < n && j >= 0 && j < m;
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'L')
                {
                    q.push({i, j});
                    ans++;
                    grid[i][j] = 'W';
                    
                   while(!q.empty())
                   {
                      int x = q.front().first;
                      int y = q.front().second;
                      q.pop();
                       
                        for(int i = 0; i < 8; i++)
                        {
                            int new_i = x + dir[i][0], new_j = y + dir[i][1];
                            if(isValid(new_i, new_j, n, m) && grid[new_i][new_j] == 'L')
                            {
                                q.push({new_i, new_j});
                                grid[new_i][new_j] = 'W';
                            }
                        }
                   }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends