//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
    bool valid(int i, int j, int r, int c)
    {
        return i >= 0 && i < r && j < c && j >= 0;
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        
        queue<pair<int, int>> q;
        
        int count = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 'X')
                {
                    count++;
                    q.push({i, j});
                    
                    grid[i][j] = 'O';
                    
                    while(!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        
                        q.pop();
                        
                        for(int k = 0; k < 4; k++)
                        {
                            if(valid(new_i + row[k], new_j + col[k], r, c) && 
                            grid[new_i + row[k]][new_j + col[k]] == 'X')
                            {
                                grid[new_i + row[k]][new_j + col[k]] = 0;
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends