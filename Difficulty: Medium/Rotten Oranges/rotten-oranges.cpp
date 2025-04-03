//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int row[4] = {-1, 1, 0, 0}; // up, down, left, right
    int col[4] = {0, 0, -1, 1}; // up, down, left, right
    int r;
    int c;
    
    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        r = grid.size();
        c = grid[0].size();
        
        queue<pair<int, int>> q;
        
        int timer = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }
        while(!q.empty())
        {
            timer++;
            int curr_orange = q.size();
            
            while(curr_orange--)
            {
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                for(int k = 0; k < 4; k++)
                {
                    if(valid(i + row[k], j + col[k]) && grid[i + row[k]][j + col[k]] == 1)
                    {
                        grid[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        if(timer == 0) return 0;
        return timer - 1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends