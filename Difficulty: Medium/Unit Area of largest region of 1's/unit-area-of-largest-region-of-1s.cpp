//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
     
    bool isValid(int i, int j, int n, int m)
    {
        return i >=0 && i < n && j >= 0 && j < m;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), maxArea = 0;
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                    int area = 1;
                    
                   while(!q.empty())
                   {
                      int x = q.front().first;
                      int y = q.front().second;
                      q.pop();
                       
                        for(int i = 0; i < 8; i++)
                        {
                            int new_i = x + dir[i][0], new_j = y + dir[i][1];
                            if(isValid(new_i, new_j, n, m) && grid[new_i][new_j] == 1)
                            {
                                q.push({new_i, new_j});
                                grid[new_i][new_j] = 0;
                                area++;
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends